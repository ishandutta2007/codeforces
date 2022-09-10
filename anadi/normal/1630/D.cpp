#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n, m, d;
int in[N];

long long solve_costs(vector <int> costs)
{
    long long ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += in[i];
    }

    for (int i = 1; i < d; ++i) {
        if (in[n + 1 - i] < 0 && -2 * in[n + 1 - i] > costs[i]) {
            ret += -2 * in[n + 1 - i] - costs[i];
        }
    }

    return ret;
}

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
    }

    d = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        d = __gcd(d, x);
    }

    int ptr = 0;
    vector <int> costs(d, MOD);

    for (int i = n - d + 1; i >= 1; --i) {
        if (in[i] < 0) {
            if (ptr == 0) {
                for (int j = 1; j < d; ++j) {
                    in[n + 1 - j] *= -1;
                }
            } else {
                in[n + 1 - ptr] *= -1;
            }

            in[i] *= -1;
        }

        costs[ptr] = min(costs[ptr], in[i]);
        ptr = (ptr + 1) % d;
    }

    for (auto &v: costs) {
        v *= 2;
    }

    long long ans = solve_costs(costs);
    for (int i = 1; i < d; ++i) {
        in[n + 1 - i] *= -1;
    }

    ans = max(ans, solve_costs(costs) - costs[0]);
    printf("%lld\n", ans);
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