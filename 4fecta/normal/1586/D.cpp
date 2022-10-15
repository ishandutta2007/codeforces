#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 105;

int n, ans[MN], ask[MN], go[MN];

int guess() {
    cout << "?";
    for (int i = 1; i <= n; i++) cout << " " << ask[i];
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) ask[i] = 1, go[i] = n + 1;
    for (int i = 1; i <= n; i++) {
        ask[i] = 2;
        int g = guess();
        if (0 < g && g < i) go[i] = g;
        ask[i] = 1;
    }
    for (int i = 1; i <= n; i++) ask[i] = 2;
    for (int i = 1; i <= n; i++) {
        ask[i] = 1;
        int g = guess();
        if (0 < g && g < i) go[g] = i;
        ask[i] = 2;
    }
    int p = n + 1, v = n;
    while (v) {
        for (int i = 1; i <= n; i++) {
            if (go[i] == p) {
                ans[i] = v;
                v--;
                p = i;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) if (!ans[i]) ans[i] = 1;
    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << ans[i];
    cout << endl;

    return 0;
}