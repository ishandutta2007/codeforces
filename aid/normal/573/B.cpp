#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], d[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int x = 1;
    for(int i = 0; i < n; i++) {
        x = min(x, a[i] - i);
        d[i] = x + i;
    }
    x = n;
    for(int i = n - 1; i >= 0; i--) {
        x = min(x, a[i] + i);
        d[i] = min(d[i], x - i);
    }
    int ans = d[0];
    for(int i = 1; i < n; i++)
        ans = max(ans, d[i]);
    cout << ans << '\n';
    return 0;
}