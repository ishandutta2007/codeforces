#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

const int NMAX = 2e5 + 15;

int v[NMAX];
int sums[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    int a, b;
    while (q --) {
        cin >> a >> b;

        ++ sums[a];
        -- sums[b + 1];
    }

    for (int i = 1; i <= n; ++ i)
        sums[i] += sums[i - 1];

    sort(sums + 1, sums + n + 1);

    lint ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans += 1ll * v[i] * sums[i];

    cout << ans << '\n';
    return 0;
}