#include <bits/stdc++.h>

using namespace std;

const int NMAX = 8000 + 5;
int digits[NMAX];

int N;
string str;
int pi[NMAX];
int dp[NMAX];

int main() {
    cin >> str;
    N = str.size();
    str = " " + str;
    for (int i = 1; i <= N; ++ i)
        digits[i] = 1 + digits[i / 10];
    digits[0] = 1;

    for (int i = N; i; -- i) {
        dp[i] = 2 + dp[i + 1];
        int k = 0;
        pi[i] = 0;
        for (int j = i + 1; j <= N; ++ j) {
            while (k && str[i + k] != str[j])
                k = pi[i + k - 1];
            if (str[i + k] == str[j])
                ++ k;
            pi[j] = k;

            int k2 = k;
            int cnt = 0;

            while (cnt < 6) {
                ++ cnt;
                int per = j - i + 1 - k2;
                if ((j - i + 1) % per == 0)
                    dp[i] = min(dp[i], dp[j + 1] + per + digits[(j - i + 1) / per]);
                if (k2)
                    k2 = pi[i + k2 - 1];
            }
        }
    }

    cout << dp[1] << endl;
    return 0;
}