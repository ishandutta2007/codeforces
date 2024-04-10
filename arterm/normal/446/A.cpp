#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 100100

int n, a[M], l[M], r[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void kill() {
    for (int i = 0; i < n; ++i) {
        l[i] = r[i] = i;
    }

    for (int i = 1; i < n; ++i)
        if (a[i - 1] < a[i])
            l[i] = l[i - 1];

    for (int i = n - 2; i >= 0; --i)
        if (a[i] < a[i + 1])
            r[i] = r[i + 1];

    int ans = 1;

    if (n >= 2) {
        ans = max(ans, r[1] - 0 + 1);
        ans = max(ans, n - 1 - l[n - 2] + 1);
    }

    for (int i = 1; i + 1 < n; ++i) {
        ans = max(ans, i - l[i - 1] + 1);
        ans = max(ans, r[i + 1] - i + 1);
        if (a[i + 1] - a[i - 1] >= 2)
            ans = max(ans, r[i + 1] - l[i - 1] + 1);
    }

    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();

    return 0;
}