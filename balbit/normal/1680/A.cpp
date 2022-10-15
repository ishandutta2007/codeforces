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
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        if (l2 > r1 || r2 < l1) {
            cout<<l1+l2<<endl;
        }else{
            cout<<max(l1, l2)<<endl;
        }
    }
}