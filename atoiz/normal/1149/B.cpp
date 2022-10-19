#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 100007, MAXM = 257;
int n, q;
int dp[MAXM][MAXM][MAXM], nxt[MAXN][26], c1, c2, c3;
int a1[MAXM], a2[MAXM], a3[MAXM];
string s;

void upd(int &a, int b) { if (a > b) a = b; }
void upd(int i, int j, int k)
{
    dp[i][j][k] = n + 1;
    if (i > 0) upd(dp[i][j][k], nxt[dp[i - 1][j][k]][a1[i]]);
    if (j > 0) upd(dp[i][j][k], nxt[dp[i][j - 1][k]][a2[j]]);
    if (k > 0) upd(dp[i][j][k], nxt[dp[i][j][k - 1]][a3[k]]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q >> s;

    s = "-" + s + "-";
    for (int i = 0; i < 26; ++i) nxt[n + 1][i] = n + 1;
    for (int i = n; i >= 0; --i) for (int j = 0; j < 26; ++j) nxt[i][j] = (s[i + 1] == ('a' + j) ? i + 1 : nxt[i + 1][j]);
    while (q--) {
        int id, k;
        char ch, c; cin >> ch >> id;
        if (ch == '+') {
            cin >> c;
            k = c - 'a';

            if (id == 1) {
                a1[++c1] = k;
                for (int i = 0; i <= c2; ++i) for (int j = 0; j <= c3; ++j) upd(c1, i, j);
            } else if (id == 2) {
                a2[++c2] = k;
                for (int i = 0; i <= c1; ++i) for (int j = 0; j <= c3; ++j) upd(i, c2, j);
            } else {
                a3[++c3] = k;
                for (int i = 0; i <= c1; ++i) for (int j = 0; j <= c2; ++j) upd(i, j, c3);
            }
        } else {
            if (id == 1) --c1;
            else if (id == 2) --c2;
            else --c3;
        }
        cout << (dp[c1][c2][c3] <= n ? "YES\n" : "NO\n");
    }
}