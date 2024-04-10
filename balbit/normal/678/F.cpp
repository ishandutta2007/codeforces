#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif


const int maxn = 3e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll ans[maxn];
struct line{
    ll m, b;
    bool operator < (const line oth) const {
        return m < oth.m;
    }
};
inline ll mydiv(ll a, ll b) {
    return a/b - ((a^b)<0 && a%b);
}
inline ll its(line &A, line &B) {
    assert (A.m != B.m);
    return mydiv(B.b-A.b,A.m-B.m);
}

vector<line> s[maxn*4];
vector<pii> ask[maxn*4];
int n;

void addline(vector<line> &vto, line L) {
    while (SZ(vto)>=2 ) {
        if (L.m == vto.back().m) {
            vto.pop_back();
        }
        else if (its(vto[SZ(vto)-2], vto.back()) >= its(vto.back(), L)){
            vto.pop_back();
        }else{
            break;
        }
    }
    if (SZ(vto) && L.m == vto.back().m) {
        vto.pop_back();
    }
    vto.pb(L);
}

void ADD(int L, int R, line Li, int o=1, int l=0, int r=n-1) {
    if (l >= L && r<=R) {
        addline(s[o], Li);
        return;
    }
    if (l>R || r<L) return;
    int mid = (l+r)/2;
    ADD(L,R,Li,o*2,l,mid);
    ADD(L,R,Li,o*2+1,mid+1,r);
}

void addq(int p, int i, int o=1, int l=0, int r = n-1) {
    if (i<l || r<i) return;
    ask[o].pb({p,i});
    if (l==r) return;
    int mid = (l+r)>>1;
    addq(p,i,o*2,l,mid);
    addq(p,i,o*2+1,mid+1,r);
}


signed main(){
    IOS();

    cin>>n;
//    map<line, pair<int, int> > mp;
    vector<pair<line, pair<int, int> > > slines;
    vector<line> added(n);
    vector<int> left(n,0);

    for (int i = 0; i<n; ++i) {
        int TP; cin>>TP;
        if (TP == 1) {
            int a,b; cin>>a>>b;
            line L = {a,b};
            added[i]=(L);
            left[i] = 1;
//            mp[L].f ++;
//            if (mp[L].f == 0) {
//                mp[L].s = i;
//            }
        }
        if (TP == 2) {
            int pos; cin>>pos; -- pos;
            left[pos]=0;
            line L = added[pos];
//            mp[L].f --;
//            if (mp[L].f == 0) {
            slines.pb({L, {pos, i}});
//            }
        }
        if (TP == 3) {
            int p; cin>>p;
            addq(p,i);
            left[i] = -1;
        }
    }
    for (int i=0; i<n; ++i) {
        if (left[i]==1) {
            slines.pb({added[i], {i,n-1}});
        }
    }
    sort(ALL(slines),[&](pair<line, pair<int, int> > a, pair<line, pair<int, int> > b) {
         if (a.f.m!=b.f.m) return a.f.m < b.f.m;
         return a.f.b < b.f.b;
    });
    for (auto & ele : slines) {
        ADD(ele.s.f, ele.s.s,ele.f);
    }
    for (int i = 0; i<n; ++i) {
        ans[i] = -inf;
    }
    for (int o = 1; o<maxn*4; ++o) {
//        bug(SZ(s[o]), SZ(ask[o]));

        if (SZ(s[o]) == 0 || SZ(ask[o]) == 0) continue;
        sort(ALL(ask[o]));
        int i = 0, j = 0;
        for (int i = 0; i<SZ(s[o]); ++i) {
            ll it = (i == SZ(s[o])-1)? inf : its(s[o][i], s[o][i+1]);
            while (j<SZ(ask[o]) && ask[o][j].f <= it) {
                ans[ask[o][j].s] = max(ans[ask[o][j].s], s[o][i].m * ask[o][j].f + s[o][i].b);
                ++j;
            }
        }
        assert( j == SZ(ask[o]));
    }
    for (int i = 0; i<n; ++i) {
        if (left[i] == -1) {
            if (ans[i] == -inf) {
                cout<<"EMPTY SET"<<endl;
            }else{
                cout<<ans[i]<<endl;
            }
        }
    }
}
/*
11
1 -2 0
1 -1 -1
1 -1 -2
3 2
2 2
3 2
3 -1
1 0 0
3 3
2 8
3 3
*/