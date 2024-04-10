#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

void solve()
{
    int n;
    scanf("%d", &n);

    vector <int> in(n);
    for (auto &v: in) {
        scanf("%d", &v);
    }

    if (n & 1) {
        puts("NO");
        return;
    }

    vector <int> ans(n);
    sort(in.begin(), in.end());

    int big = n;
    int small = n / 2;

    for (int i = 0; i < n; i += 2) {
        ans[i] = in[--big];
        ans[i + 1] = in[--small];
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] > ans[(i + 1) % n] && ans[i] > ans[(i + n - 1) % n]) {
            continue;
        }

        if (ans[i] < ans[(i + 1) % n] && ans[i] < ans[(i + n - 1) % n]) {
            continue;
        }

        puts("NO");
        return;
    }

    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }

    puts("");
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