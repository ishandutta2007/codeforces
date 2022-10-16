#include <bits/stdc++.h>

// 1:29
using namespace std;

#define all(v) (v).begin(), (v).end()
const int NMAX = 2 * 1000 + 5;

double dp[NMAX][NMAX];

double get_dp(int i, int j) {
    if (i < 0 || j < 0)
        return 0;
    return dp[i][j];
}

int main()
{
    //freopen("data.in", "r", stdin);

    int N, m;
    cin >> N >> m;

    vector <int> lines, cols;
    while (m --) {
        int x, y;
        cin >> x >> y;
        lines.push_back(x);
        cols.push_back(y);
    }
    sort(all(lines));
    sort(all(cols));
    lines.resize(unique(all(lines)) - lines.begin());
    cols.resize(unique(all(cols)) - cols.begin());

    int remX = N - lines.size();
    int remY = N - cols.size();

    for (int i = 0; i <= remX; ++ i)
        for (int j = 0; j <= remY; ++ j)
            if (i || j) {
                const int both = i * j;
                const int just_i = i * N - both;
                const int just_j = j * N - both;
                const int neighter = N * N - both - just_i - just_j;

                dp[i][j] = (1.0 * N * N + just_i * get_dp(i - 1, j) + just_j * get_dp(i, j - 1) + both * get_dp(i - 1, j - 1)) / (1.0 * N * N - 1.0 * neighter);
            }

    cout << fixed << setprecision(12) << dp[remX][remY] << endl;
    return 0;
}