#include <iostream>
#include <algorithm>
#include <bitset>

#define lint long long int
using namespace std;

const int NMAX = 4000 + 5;
const int INF = 2e9 + 5;

int n;
int v[NMAX];

int s_part[NMAX];
inline int sum(int l, int r) {
    return s_part[r] - s_part[l - 1];
}

int dp[90][2][3000][190];
bitset <190> vis[90][2][3000];

int compute(int k, bool whose, int l, int r) {
    if (l + k - 1 > r)
        return 0;

    if (vis[k][whose][l][r - l])
        return dp[k][whose][l][r - l];
    vis[k][whose][l][r - l] = true;

    int ans = -INF;
    if (whose == 0) {
        ans = sum(l, l + k - 1) - compute(k, 1, l + k, r);
        if (l + k <= r)
            ans = max(ans, sum(l, l + k) - compute(k + 1, 1, l + k + 1, r));
    }
    else {
        ans = sum(r - k + 1, r) - compute(k, 0, l, r - k);
        if (r - k >= l)
            ans = max(ans, sum(r - k, r) - compute(k + 1, 0, l, r - k - 1));
    }

    dp[k][whose][l][r - l] = ans;
    return ans;

}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    for (int i = 1; i <= n; ++ i)
        s_part[i] = v[i] + s_part[i - 1];

    cout << compute(1, 0, 1, n) << '\n';
    return 0;
}