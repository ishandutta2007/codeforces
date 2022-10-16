#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000000 + 7;

inline void add(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

const int NMAX = 75;
int dp[NMAX + 1][1 << 20];

int N;
string str;

vector <int> goods;

int main()
{
    int val = 1;
    while (val <= 2000000) {
        goods.push_back(val);
        val *= 2;
        val ++;
    }

    cin >> N;
    cin >> str; str = " " + str;

    int ans = 0;
    for (int i = 0; i <= N; ++ i) {
        dp[i][0] = 1;

        if (i < N) {
            int start = i + 1;
            while (start <= N && str[start] == '0')
                ++ start;

            for (int mask = 0; mask < (1 << 20); ++ mask)
                if (dp[i][mask]) {
                    int k = start;
                    int nr = 0;
                    while (k <= N) {
                        nr = (2 * nr + str[k] - '0');
                        if (nr > 20)
                            break;

                        add(dp[k][mask | (1 << (nr - 1))], dp[i][mask]);
                        ++ k;
                    }
                }
        }

        for (auto it: goods)
            if (dp[i][it])
                add(ans, dp[i][it]);
    }

    cout << ans << '\n';
    return 0;
}