#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll d, k, a, b, t;
void solve() {
    cin >> d >> k >> a >> b >> t;
    ll ans = 0;
    if(k >= d) {
        cout << d * a << "\n";
        return;
    }
    {
        ll K = (d - 1)/k;
        ans = K * (k * a + t) + (d - K * k) * a;
    }
    d -= k;
    ll x = d/k;
    ans = min(ans, k * a + min(d * b, x * k * a + t * x + min(t + (d % k) * a, (d % k) * b)));
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}