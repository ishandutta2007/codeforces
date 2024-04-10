#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

const int INF = 1e9 + 15;

int getMask(char ch) {
    if (isalpha(ch))
        return 1;
    if (isdigit(ch))
        return 2;
    return 4;
}

int N, M;
string strs[55];

int dp[55][8];

void upd(int &where, int val) {
    if (val < where)
        where = val;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i)
        cin >> strs[i];

    for (int i = 0; i < 55; ++ i)
        for (int j = 0; j < 8; ++ j)
            dp[i][j] = INF;

    dp[0][0] = 0;
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < 8; ++ j) {
            for (int p = 0; p < M; ++ p) {
                int cost = min(p, M - p);
                upd(dp[i + 1][j | getMask(strs[i + 1][p])], dp[i][j] + cost);
            }
        }

    cout << dp[N][7] << '\n';
    return 0;
}