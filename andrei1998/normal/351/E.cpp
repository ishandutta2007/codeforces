#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2000 + 5;
const int VALMAX = 1E6;
typedef long long int lint;
const lint INF = 1E18;

int N;
int v[NMAX];
int lessRight[NMAX];
int lessLeft[NMAX];

vector <int> freq[VALMAX];

int p[NMAX];
int p_size;
lint dp[NMAX][NMAX];

int main()
{
    //freopen("data.in", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        v[i] = abs(v[i]);
        freq[v[i]].push_back(i);
    }

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (i != j && v[j] < v[i]) {
                if (j < i)
                    ++ lessLeft[i];
                else
                    ++ lessRight[i];
            }


    lint ans = 0;
    for (int val = 1; val < VALMAX; ++ val) if (!freq[val].empty()) {
        p_size = 0;
        for (auto it: freq[val])
            p[++ p_size] = it;

        for (int i = 0; i <= p_size + 1; ++ i)
            for (int j = 0; j <= p_size + 1; ++ j)
                dp[i][j] = INF;
        dp[0][0] = 0;

        for (int i = 1; i <= p_size; ++ i) {
            const int where = p[i];
            for (int j = 0; j <= i; ++ j) {
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + lessRight[where]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + lessLeft[where] + j);
            }
        }

        lint best = INF;
        for (int j = 0; j <= p_size; ++ j)
            best = min(best, dp[p_size][j]);
        ans += best;
    }

    cout << ans << '\n';
    return 0;
}