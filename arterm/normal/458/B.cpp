#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

#define long long long
#define INF 1000000000000000000ll
#define M 100100

int n, m;
long a[M], b[M], sa = 0, sb = 0;

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sa += a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sb += b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
}

void kill() {
    long ans = INF;

    long s = sb;
    for (int i = 0; i + 1 < n; ++i) {
        s += min(a[i], sb);
    }

    ans = min(ans, s);

    s = sa;
    for (int j = 0; j + 1 < m; ++j) {
        s += min(b[j], sa);
    }

    ans = min(s, ans);

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