#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int a[] = {500, 1000, 1500, 2000, 2500};
int b[5];
int w[5];
void solve() {
    for(int i = 0; i < 5; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < 5; i++) {
        cin >> w[i];
    }
    int x, y;
    cin >> x >> y;
    int ans = x * 100 - 50 * y;
    for(int i = 0; i < 5; i++) {
        ans += max(a[i] * 3/10, (250 - b[i]) * a[i]/250 - 50 * w[i]);
    }
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