#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int NMAX = 1000 + 5;

int maxAp[26];

int N;
string str;

bool works[NMAX][NMAX];

const int MOD = 1000000000 + 7;

int dp[NMAX];
int cnt[NMAX];
bool freq[26];

int main()
{
    cin >> N;
    cin >> str; str = " " + str;
    for (int i = 0; i < 26; ++ i)
        cin >> maxAp[i];

    int subtask2 = 0;
    for (int start = 1; start <= N; ++ start) {
        for (int k = 0; k < 26; ++ k)
            freq[k] = false;
        for (int i = start; i <= N; ++ i) {
            bool bad = false;
            freq[str[i] - 'a'] = true;

            for (int k = 0; k < 26; ++ k)
                if (freq[k] && i - start + 1 > maxAp[k])
                    bad = true;

            if (bad)
                break;
            works[start][i] = true;

            if (i - start + 1 > subtask2)
                subtask2 = i - start + 1;
        }
    }

    cnt[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        dp[i] = i;
        cnt[i] = 0;
        for (int j = 1; j <= i; ++ j)
            if (works[j][i]) {
                cnt[i] += cnt[j - 1];
                if (cnt[i] >= MOD)
                    cnt[i] -= MOD;
                dp[i] = min(dp[i], 1 + dp[j - 1]);
            }
    }

    cout << cnt[N] << '\n';
    cout << subtask2 << '\n';
    cout << dp[N] << '\n';
    return 0;
}