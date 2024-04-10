#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define pb push_back

#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBITR


const int maxn = 3e5+5;



signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);

    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<vector<int> > a(n,vector<int> (m));

        REP(i,n) {
            REP(j,m) {
                cin>>a[i][j];
            }
        }

        int I=0, J=0; int gap = 1;
        REP(i,n) {
            int big = -1;
            REP(j,m) {
                if (big == -1 || a[i][j] > a[i][big]) {
                    big = j;
                }
                if (a[i][big] - a[i][j] >= gap) {
                    gap = a[i][big] - a[i][j];
                    I = big; J = j;
                }
            }
        }
        REP(i,n) swap(a[i][I], a[i][J]);
        bool ok = 1;
        REP(i,n) {
            REP(j,m-1) {
                if (a[i][j] > a[i][j+1]) ok = 0;
            }
        }
        if (!ok) cout<<-1<<endl;
        else cout<<I+1<<' '<<J+1<<endl;
    }

}