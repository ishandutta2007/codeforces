#include <iostream>
#include <string>

using namespace std;

string text;
string str;

const int NMAX = 100000 + 5;
const int INF = 2E9;

int pi[NMAX];
int trans[NMAX][26];

int dp[2][NMAX];

void upd(int &where, int val) {
    if (val > where)
        where = val;
}

int main()
{
    cin >> text;
    int M = text.size();
    text = " " + text;

    cin >> str;
    int N = str.size();
    str = " " + str;

    int k = 0;
    for (int i = 2; i <= N; ++ i) {
        while (k && str[i] != str[k + 1])
            k = pi[k];
        if (str[i] == str[k + 1])
            ++ k;
        pi[i] = k;
    }

    for (int i = 0; i <= N; ++ i)
        for (char ch = 'a'; ch <= 'z'; ++ ch) {
            if (i < N && str[i + 1] == ch)
                trans[i][ch - 'a'] = i + 1;
            else
                trans[i][ch - 'a'] = trans[pi[i]][ch - 'a'];
        }

    for (int i = 1; i <= N; ++ i)
        dp[0][i] = -INF;

    for (int i = 0; i < M; ++ i) {
        for (int st = 0; st <= N; ++ st)
            dp[(i + 1) & 1][st] = -INF;

        if (text[i + 1] == '?') {
            for (int st = 0; st <= N; ++ st)
                if (dp[i & 1][st] > -INF)
                    for (char ch = 'a'; ch <= 'z'; ++ ch)
                        upd(dp[(i + 1) & 1][trans[st][ch - 'a']], dp[i & 1][st] + (trans[st][ch - 'a'] == N));
        }
        else {
            for (int st = 0; st <= N; ++ st)
                if (dp[i & 1][st] > -INF)
                    upd(dp[(i + 1) & 1][trans[st][text[i + 1] - 'a']], dp[i & 1][st] + (trans[st][text[i + 1] - 'a'] == N));
        }
    }

    int ans = 0;
    for (int st = 0; st <= N; ++ st)
        upd(ans, dp[M & 1][st]);
    cout << ans << '\n';
    return 0;
}