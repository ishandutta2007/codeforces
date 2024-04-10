#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100005;
struct beacon {
    int x, power;

    beacon(int _x = 0, int _power = 0): x(_x), power(_power) {}
} v[NMAX];

bool operator<(const beacon &a, const beacon &b) {
    return a.x < b.x;
}

int dp[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].x >> v[i].power;
    sort(v + 1, v + n + 1);

    int ans = n + 5;

    for (int i = 1; i <= n; ++ i) {
        int j = lower_bound(v + 1, v + n, v[i].x - v[i].power) - v;
        dp[i] = dp[j - 1] + i - j;

        if (dp[i] + n - i < ans)
            ans = dp[i] + n - i;
    }

    cout << ans << '\n';
    return 0;
}