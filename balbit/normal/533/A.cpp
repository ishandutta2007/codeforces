#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 5e5+5;
int h[maxn];
vector<int> g[maxn];
vector<int> s; // sorted by worst (tallest) miners to best
vector<int> reach; // how many places can this miner reach?

int minpar[maxn];
int par[maxn];
int hat[maxn];
//int bat[maxn];

void dfs(int v, int p) {
    minpar[v] = h[v];
    par[v] = p;
    if (p!=-1) {
        MN(minpar[v], minpar[p]);
    }
    {
        hat[v] = lower_bound(ALL(s), h[v], greater<int>()) - s.begin();
        int at = lower_bound(ALL(s), minpar[v], greater<int>()) - s.begin();
//        bat[v] = at;
        reach[at]++;
    }
    for (int u : g[v]) {
        if (u!=p) dfs(u, v);
    }
}

int L = inf, R = -1;
//int tmp[maxn];

vector<int> needy;
vector<int> have;

void dfs3(int v, int p, int nat,bool fafa) {
    if (!fafa) MX(nat, hat[v]);
    if (nat > R) return;
    have.pb(nat);
    for (int u : g[v]) {
        if (u != p) {
            dfs3(u, v, nat,0);
        }
    }
}

ll re = inf;

void dfs2(int v, int p) {
    int M = p == -1? iinf : minpar[p];
    if (h[v] < M) {
        bug(v, M, h[v]);
        if (h[v] < s[R]) { // s[R] is the smallest guy we have to help
            // have to end here
            if (M >= s[L]) {
                // give it a shot
                // set h[v] to be s[L]
                int bef = h[v];
                h[v] = s[L];
                // do stuff

                int mplace = lower_bound(ALL(s), M, greater<int>()) - s.begin();

                int l = mplace, r = L+1; // binary search

                bug(l,r);

                while (l!=r) {
                    bool ok = 1;
                    int mid = (l+r)/2;
                    have.clear();
                    dfs3(v, p, mid,1);
                    sort(ALL(have));
                    REP(i, SZ(needy)) {
                        if (i == SZ(have) || have[i] > needy[i]) {
                            // dead
                            ok = 0; break;
                        }
                    }
                    if (ok) {
                        bug("ok!!");
                        l = mid+1;
                    }else{
                        r = mid;
                    }
                }

                bug(l,r);

                h[v] = bef;
                if (l != mplace) {
                    MN(re, s[l-1] - h[v]);
                }

                return;

            }

            return;
        }else{
            for (int u : g[v]) {
                if (u != p) {
                    dfs2(u,v);
                }
            }
        }
    }else{
        for (int u : g[v]) {
            if (u != p) {
                dfs2(u,v);
            }
        }
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) {
        cin>>h[i];
    }
    REP(i,n-1) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    int m; cin>>m;
    s.resize(m); reach.resize(m+1);
    REP(i,m) cin>>s[i];
    sort(ALL(s), greater<int>());

    dfs(0,-1);

    REP(i,m) {
        if (i) reach[i] += reach[i-1];
        bug(i, s[i], reach[i]);
    }
    int mostneedy = 0;
    REP(i,m) {
        reach[i] -= i+1;
        bug(i, reach[i]);
        if (reach[i] < 0) {
            MN(L, i); MX(R, i);
            if (-reach[i] > mostneedy) {
                REP(j, -mostneedy - reach[i]) {
                    needy.pb(i); bug(i, "need!");
                }
                mostneedy = -reach[i];
            }
        }
    }

    bug(L,R);
    if (L == inf) {
        cout<<0<<endl; return 0;
    }

    dfs2(0, -1);
    if (re == inf) cout<<-1<<endl;
    else cout<<re<<endl;
}

/*
4
3 6 6 4
1 2
2 3
3 4
1
100
*/