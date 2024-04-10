#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
using namespace std;

const int INF = 1e9 + 15;
const int mod = 1000000007;

int main()
{
    lint a, b;
    cin >> a >> b;

    int ans = 0;

    lint nr;
    for (int i = 1; i <= 63; ++ i)
        for (int j = 0; j < i - 1; ++ j) {
            nr = (1ll << i) - 1 - (1ll << j);

            if (a <= nr && nr <= b)
                ++ ans;
        }

    cout << ans << '\n';
    return 0;
}