#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 4e5+5;

int to[maxn];
bool A[maxn], done[maxn];

vector<int> g[maxn];
int fr = 0, ttt = 0;
bool seen[maxn];
void dfs(int v, int c) {
    fr += 1; ttt += c ^ A[v]; seen[v] = 1;
    for (int u : g[v]) {
        if (!seen[u]) {
            dfs(u,c^1);
        }
    }
}

signed main(){
    IOS();
    int n; cin>>n;
//    int minb = 10000000, maxa = -1;
    REP(i,n) {
        int a,b; cin>>a>>b; --a; --b;
        bool xx = 0;
        if (a>b) {

            swap(a,b); xx = 1;
        }
//        MN(minb, b);
//        MX(maxa, a);
        if (b < n || a>=n) {
            GG();
        }
        to[a] = b;
        A[a] = xx;
    }
    int nowr = -1;
    int re = 0;
    for (int i = n-1; i>=0; --i) {
        if (to[i] > nowr) {
            nowr = to[i]; done[i] = 1;
//            re += A[i]==0;
        }
    }
    bug(nowr);
    nowr = -1;
    for (int i = n-1; i>=0; --i) {
        if (done[i]) continue;
        if (to[i] > nowr) {
            nowr = to[i]; done[i] = 1;
//            re += A[i]==1;
        }else{
            GG();
        }
    }
    nowr = 0; int who = -1;
    vector<int> pp;
    for (int i = n-1; i>=0; --i) {
        if (to[i] < nowr) {
            g[i].pb(who); g[who].pb(i);
            while (!pp.empty() && to[pp.back()] > to[i]) {
                g[i].pb(pp.back()); g[pp.back()].pb(i);
                pp.pop_back();
            }
            pp.pb(who);
        }else{
            nowr = to[i]; who = i;
            pp.pb(i);
        }
    }
    REP(i,n) {
        if (!seen[i]) {
            ttt = fr = 0;
            dfs(i,0);
            bug(i, ttt, fr);
            re += min(fr-ttt, ttt);
        }
    }
    bug(re);
    cout<<re<<endl;

}