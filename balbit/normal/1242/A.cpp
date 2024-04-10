#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(i) int(i.size())
#define eb emplace_back
#ifdef BTC
#define IOS()
#define debug(...) fprintf(stderr,"%s - %d (%s) =",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y) {cerr<<x<<",";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif // BTC
const int MAXN = 1e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

/*********GOOD_LUCK**************/

int main () {
    IOS();
    ll n;
    cin >> n;
    ll cnt = 0;
    ll cur = 0;
    for (ll i=2;i<=sqrt(n);i++) {
        if (n % i == 0) {
            cnt++;
            cur = i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) cnt++, cur = n;
    debug(cnt);
    if (cnt == 0) cout << n <<endl;
    else if (cnt == 1) cout << cur << endl;
    else cout << 1 <<endl;

    return 0;
}