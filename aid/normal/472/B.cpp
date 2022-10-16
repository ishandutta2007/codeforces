#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i += k) {
        int h = 0;
        for(int j = i; j < i + k && j < n; j++)
            h = max(h, a[j]);
        ans += 2 * h;
    }
    cout << ans << '\n';
    return 0;
}