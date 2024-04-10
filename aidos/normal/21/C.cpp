#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
int a[maxn];
void solve() {
    cin >> n;
    int s = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if(s % 3 != 0) {
        cout << 0 << "\n";
        return;
    }
    ll ans = 0;
    int c1 = 0, c2 = 0;
    int cur = 0;
    for(int i = 1; i < n; i++) {
        cur += a[i];

        if(cur == 2 * s/3) {
            ans += c1;
        }
        if(cur == s/3) c1++;
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
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}