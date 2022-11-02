#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define filename ""
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
ll n, k, A, B;
void solve() {
    cin >> n >> k >> A >> B;
    ll ans = (n-1) * A;
    if(k > 1) {
        ll cur = 0;
        while(n >= k) {
            ans = min(ans, cur + (n-1) * A);
            ll d = n/k * k;
            cur += (n-d) * A;
            n = d/k;
            cur += B;
        }
        ans = min(ans, cur + (n-1) * A);
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}