#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100005;
const int MOD = 10007;

int n;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans = (ans + 1LL * v[i] * v[n - i + 1]) % MOD;

    cout << ans << '\n';
    return 0;
}