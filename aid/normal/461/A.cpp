#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 300 * 1000 + 5;
long long a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        ans += a[i] + a[i + 1];
        a[i] += a[i + 1];
    }
    ans += a[0];
    cout << ans << '\n';
    return 0;
}