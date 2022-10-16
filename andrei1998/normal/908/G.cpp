#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000 + 7;

const int NMAX = 705 + 5;

int N;
int nr[NMAX];

//fie il numeri, fie opresti numaratoarea
//dp[primele where cifre au fost procesate][atatea cifre sunt mai mici ca digit][ne-a dat mai mic ca nr][nu mai numaram digit]
int dp[NMAX][NMAX][2][2];

static inline void add(int &where, const int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

static void computeDp(int digit) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = 1;
    for (int where = 0; where < N; ++ where)
        for (int cnt = 0; cnt <= where; ++ cnt) {
            //Intai daca nu e deja mai mic
            for (int c = 0; c <= nr[where + 1]; ++ c) {
                if (c != digit) {
                    add(dp[where + 1][cnt + (c >= 0 && c < digit)][c < nr[where + 1]][0], dp[where][cnt][0][0]);
                    add(dp[where + 1][cnt + (c >= 0 && c < digit)][c < nr[where + 1]][1], dp[where][cnt][0][1]);
                }
                else {
                    add(dp[where + 1][cnt + 1][c < nr[where + 1]][0], dp[where][cnt][0][0]);

                    add(dp[where + 1][cnt + 1][c < nr[where + 1]][1], dp[where][cnt][0][0]);
                    add(dp[where + 1][cnt][c < nr[where + 1]][1], dp[where][cnt][0][1]);
                }
            }

            //Apoi, daca e deja mai mic
            for (int c = 0; c < 10; ++ c) {
                if (c != digit) {
                    add(dp[where + 1][cnt + (c >= 0 && c < digit)][1][0], dp[where][cnt][1][0]);
                    add(dp[where + 1][cnt + (c >= 0 && c < digit)][1][1], dp[where][cnt][1][1]);
                }
                else {
                    add(dp[where + 1][cnt + 1][1][0], dp[where][cnt][1][0]);
                    add(dp[where + 1][cnt + 1][1][1], dp[where][cnt][1][0]);
                    add(dp[where + 1][cnt][1][1], dp[where][cnt][1][1]);
                }
            }
        }
}

int main()
{
    string str;
    cin >> str;

    for (int i = 1; i <= str.size(); ++ i)
        nr[i] = str[i - 1] - '0';
    N = str.size();

    int ans = 0;
    for (int digit = 1; digit < 10; ++ digit) {
        computeDp(digit);
        int pow10 = 1;
        for (int pos = N; pos; -- pos) {
            const int ways = (dp[N][pos][0][1] + dp[N][pos][1][1]) % MOD;
            ans = (ans + 1LL * ((1LL * ways * pow10) % MOD) * digit) % MOD;
            pow10 = (10LL * pow10) % MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}