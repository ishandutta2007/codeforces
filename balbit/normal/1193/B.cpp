#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<" "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#define IOS()
#else
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#define bug(...)
#endif // BALBIT

#define pb push_back
#define SZ(x) (int) ((x).size())

const int maxn = 1e5+5;

int n;

struct seg{
    ll s[maxn*4];
    ll tag[maxn*4];
    bool tags[maxn*4];
    set<int, greater<int> > st;

    void push(int o, int l, int r) {
        if (tags[o]) {
            tag[o] = 0;
            s[o] = 0;
            if (l!=r) {
                tags[o*2] = 1;
                tags[o*2+1] = 1;
            }
            tags[o] = 0;
            return;
        }
        if (tag[o]) {
            s[o] = s[o] + tag[o];
            if (l!=r) {
                tag[o*2] += tag[o];
                tag[o*2+1] += tag[o];
            }
            tag[o] = 0;
        }
    }

    void MOO(int p, ll val, int o=1, int l = 0, int r = maxn-1) {
        push(o,l,r);
        if (l > p || r<p) {
            return;
        }
        if (l >= p && r<=p) {
            s[o] = val;
            push(o,l,r);
            return;
        }
        int mid = (l+r)/2;
        MOO(p,val,o*2,l,mid);
        MOO(p,val,o*2+1,mid+1,r);
        s[o] = max(s[o*2], s[o*2+1]);
    }

    void MOadd(int L, int R, ll val, int o=1, int l = 0, int r = maxn-1) {
        push(o,l,r);
        if (l > R || r<L) {
            return;
        }
        if (l >= L && r<=R) {
            tag[o] += val;
            push(o,l,r);
            return;
        }
        int mid = (l+r)/2;
        MOadd(L,R,val,o*2,l,mid);
        MOadd(L,R,val,o*2+1,mid+1,r);
        s[o] = max(s[o*2], s[o*2+1]);
    }

    inline void MO(int p, ll val) {
        st.insert(p);
        MOO(p,val);
    }

    ll QU (int L, int R, int o=1, int l = 0, int r = maxn-1) {
        if (l > R || r<L) return 0;
        push(o,l,r);
        if (l >= L && r<=R) {
            return s[o];
        }
        int mid = (l+r)/2;
        return max(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
    }

    void clear(){
        tags[1] = 1;
        st.clear();
    }

    seg(){
        memset(s,0,sizeof s);
        memset(tags,0,sizeof tags);
        memset(tag,0,sizeof tag);
    }
};

vector<int> g[maxn];
ll w[maxn];
int a[maxn], sz[maxn], big[maxn];

seg tmps[20];
int tat = -1;

void dfs1(int v, int p) {
    sz[v] = 1;
    big[v] = -1;
    for (int u : g[v]) {
        if (u != p) {
            dfs1(u,v);
            if (big[v] == -1 || sz[u] > sz[big[v]]) {
                big[v] = u;
            }
            sz[v] += sz[u];
        }
    }
}

void dfs(int v, int p, seg &s) {
    if (big[v] == -1) {
        // is leaf
        s.MO(a[v], w[v]);
        bug(v+1,"is a leaf", s.QU(0,maxn-1));
        return;
    }
    dfs(big[v],v,s);
    for (int u : g[v]) {
        if (u != p && u != big[v]) {
            ++tat;
            dfs(u, v, tmps[tat]);
            int prvpt = maxn;
            for (int pt : tmps[tat].st) {
                bug(v+1, pt, tat);
                bug(tmps[tat].QU(pt, pt));
                bug(s.QU(0,pt));

                int myval = tmps[tat].QU(0,pt);
                if (myval <= 0) continue;
                s.MOadd(pt+1, prvpt-1, myval);
                s.MO(pt, s.QU(0,pt) + myval);
                prvpt = pt;
            }
            tmps[tat].clear();
            --tat;
        }
    }
    s.MO(a[v], w[v] + s.QU(0,a[v]));
    bug(v+1, s.QU(0,maxn-1));
}

signed main(){
    IOS();
    int m,k; cin>>n>>m>>k;
    for (int i = 1; i<n; ++i) {
        int p; cin>>p; --p;
        g[p].pb(i);
    }
    dfs1(0,0);
    for (int i = 0; i<m; ++i) {
        int v,d,wowo; cin>>v>>d>>wowo;
        --v;
        a[v] = d;
        w[v] = wowo;
    }
    bug("Hey yo wassup");
    ++tat;
    dfs(0,0,tmps[tat]);
    cout<<tmps[tat].QU(0,maxn-1)<<endl;
}