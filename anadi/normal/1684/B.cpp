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
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int k = c / b * b;
    k += a;

    while (k <= c) {
        k += b;
    }

    printf("%d %d %d\n", k, b, c);
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