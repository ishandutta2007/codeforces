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
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> in(n);

    long long ans = -1LL * k * (k - 1) / 2;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
        ans += in[i];

        in[i] = -in[i] + (n - i - 1);
    }

    sort(in.begin(), in.end());
    for (int i = 0; i < k; ++i) {
        ans += in[i];
    }

    printf("%lld\n", ans);
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