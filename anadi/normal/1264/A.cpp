#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> in(n);
    for (auto &v: in) {
        scanf("%d", &v);
    }

    if (in[n - 1] == in[0]) {
        puts("0 0 0");
        return;
    }

    int g = 0, s = 0, b = 0;
    for (int i = 1; i < n; ++i) {
        if (in[i] != in[i - 1]) {
            g = i;
            break;
        }
    }

    for (int j = g + 1; j < n; ++j) {
        if (j - g <= g) {
            continue;
        }

        if (in[j] != in[j - 1]) {
            s = j;
            break;
        }
    }

    if (s == 0) {
        puts("0 0 0");
        return;
    }

    for (int j = s + 1; j < n; ++j) {
        if (j - s <= g) {
            continue;
        }

        if (in[j] != in[j - 1]) {
            b = j;
            break;
        }
    }

    if (b == 0 || 2 * b > n) {
        puts("0 0 0");
        return;
    }

    while (true) {
        int nxt = b + 1;
        while (nxt < n && in[nxt] == in[nxt - 1]) {
            ++nxt;
        }

        if (nxt * 2 <= n) {
            b = nxt;
        } else {
            break;
        }
    }

    printf("%d %d %d\n", g, s - g, b - s);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}