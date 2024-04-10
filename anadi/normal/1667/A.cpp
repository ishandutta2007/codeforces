#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector <int> vec(n);
    for (auto &v: vec) {
        scanf("%d", &v);
    }

    auto solve = [&](int from, int to, int dir) {
        long long last = 0;
        long long res = 0;

        while (from != to) {
            long long nxt = (last + vec[from]) / vec[from];
            res += nxt;

            last = nxt * vec[from];
            from += dir;
        }

        return res;
    };

    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, solve(i - 1, -1, -1) + solve(i + 1, n, 1));
    }

    printf("%lld\n", ans);
    return 0;
}