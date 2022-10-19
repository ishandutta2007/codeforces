#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 300300

int n, a[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void kill() {
    sort(a, a + n);
    reverse(a, a + n);
    long long ans = 1ll * n * a[0];
    for (int i = 1; i < n; ++i)
        ans += 1ll * (n - i + 1) * a[i];
    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    read();
    kill();

    return 0;
}