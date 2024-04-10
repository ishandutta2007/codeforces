#include <bits/stdc++.h>

using namespace std;

const int N = 2'007;
const int MOD = 998'244'353;
const vector <char> brackets = {'(', ')'};

int n;
char in[N];
int pref[N];

int pw2[N];
int dp[N][N][3];

void add(int &cur, int v)
{
    cur += v;
    if (cur >= MOD) {
        cur -= MOD;
    }
}

bool match(char goal, char c)
{
    if (c == '?') {
        return true;
    }

    return c == goal;
}

int main()
{
    scanf("%s", in + 1);
    n = strlen(in + 1);

    pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw2[i] = 2 * pw2[i - 1] % MOD;
        pref[i] = pref[i - 1] + (in[i] == '?');
    }

    for (int len = 1; len < n; ++len) {
        for (int s = 1; s + len <= n; ++s) {
            int e = s + len;
            for (int type = 0; type < 3; ++type) {
                for (char cs: brackets) {
                    if (!match(cs, in[s])) {
                        continue;
                    }

                    if (cs == ')' && type == 1) {
                        continue;
                    }
    
                    for (char ce: brackets) {
                        if (!match(ce, in[e])) {
                            continue;
                        }

                        if (ce == '(' && type == 2) {
                            continue;
                        }

                        if (cs == '(' && ce == ')') {
                            add(dp[s][e][type], dp[s + 1][e - 1][0]);
                            add(dp[s][e][type], pw2[max(0, pref[e - 1] - pref[s])]);
                        } else if (cs == '(') {
                            add(dp[s][e][type], dp[s][e - 1][1]);
                        } else if (ce == ')') {
                            add(dp[s][e][type], dp[s + 1][e][2]);
                        } else {
                            add(dp[s][e][type], dp[s + 1][e - 1][0]);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", dp[1][n][0]);
    return 0;
}