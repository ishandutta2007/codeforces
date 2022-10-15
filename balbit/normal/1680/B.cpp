#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define int ll
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)

#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define pb push_back
#define SZ(x) (int)((x).size())

#define ALL(x) (x).begin(), (x).end()

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<" "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x ) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif

signed main(){
    ios::sync_with_stdio(0);
    bug(1,2);
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        pii m1 = {100000, 100000};
        pii m2 = m1;
        REP(i,n) REP(j,m) {
            char c; cin>>c; 
            if (c == 'E') continue;
            MN(m1, make_pair(i,j)); MN(m2, make_pair(j,i));
        }
        swap(m2.f, m2.s);
        cout<<(m1==m2?"YES":"NO")<<endl;
    }
}