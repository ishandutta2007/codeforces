#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 205;

int n, f[MAX_N], cyc_len[MAX_N], start[MAX_N];

long long __gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }

    return __gcd(b, a % b);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> f[i];

        f[i]--;
    }

    for (int i = 0; i < n; i++) {
        int vis[MAX_N], cnt = 0;

        memset(vis, -1, sizeof(vis));

        int j;

        for (j = i; vis[j] < 0; j = f[j], cnt++) {
            vis[j] = cnt;
        }

        start[i] = vis[j];
        cyc_len[i] = cnt - vis[j];
    }

    long long ans = 1;

    for (int i = 0; i < n; i++) {
        ans = ans * cyc_len[i] / __gcd(ans, cyc_len[i]);
    }

    long long mx = 1;
    for (int i = 0; i < n; i++) {
        if (start[i] > ans) {
            mx = max(mx, (start[i] + ans - 1) / ans);
        }
    }

    cout << ans * mx << endl;

    return 0;
}