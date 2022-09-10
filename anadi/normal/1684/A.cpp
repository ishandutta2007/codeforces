#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

void solve()
{
    int n;
    scanf("%d", &n);

    if (n < 100) {
        printf("%d\n", n % 10);
    } else {
        int best = 10;
        while (n) {
            best = min(best, n % 10);
            n /= 10;
        }

        printf("%d\n", best);
    }
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}