#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define pb push_back
#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) for (int i = 1; i<=n; ++i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT


const int maxn = 3e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;


signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    bug(1,2,rnd());

    int t; cin>>t;
    while (t--) {
        int n,g,b; cin>>n>>g>>b;
        int ON = n;
        n = ((n+1)/2);
        int take = (n-1) / (g);
        int re = take * (g+b);
        n = n - take * g;
        assert(n <= g);
        re += n;
        cout<<max(ON,re)<<endl;

    }

}