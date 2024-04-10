#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string str;

const int NMAX = 100000 + 5;
const int INF = 1000000000 + 5;
int dp[NMAX][3];
bool used[NMAX][3];

void update(int &where, int val, bool &us, bool da) {
    if (val > where) {
        where = val;
        us = da;
    }
}

int main()
{
    cin >> str;
    N = str.size();
    str = " " + str;

    for (int t = 0; t <= N; ++ t)
        for (int j = 0; j < 3; ++ j)
            dp[t][j] = -INF;

    for (int i = 0; i < N; ++ i) {
        //Use digit alone
        if (str[i + 1] != '0')
            update(dp[i + 1][(str[i + 1] - '0') % 3], 1, used[i + 1][(str[i + 1] - '0') % 3], 1);

        for (int r = 0; r < 3; ++ r) {
            //Don't use digit
            update(dp[i + 1][r], dp[i][r], used[i + 1][r], 0);

            //Use digit
            update(dp[i + 1][(r + str[i + 1] - '0') % 3], 1 + dp[i][r], used[i + 1][(r + str[i + 1] - '0') % 3], 1);
        }
    }

    if (dp[N][0] < 0) {
        for (int i = 1; i <= N; ++ i)
            if ((str[i] - '0') % 3 == 0) {
                cout << str[i] << '\n';
                return 0;
            }

        cout << "-1\n";
        return 0;
    }
    int r = 0;
    int cnt = dp[N][r];

    string ans;
    for (int i = N; i && cnt; -- i) {
        if (used[i][r]) {
            ans += str[i];
            r -= (str[i] - '0');
            r %= 3;
            if (r < 0)
                r += 3;
            cnt --;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}