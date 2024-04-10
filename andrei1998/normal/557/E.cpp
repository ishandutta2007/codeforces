#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
#define NMAX 5005
using namespace std;

char sir[5005];
int dp[5005][5005];
bool les[5005][5005];

bool palin[5005][5005];

struct interv {
    int st, dr;
} v[5005 * 5005];

bool operator< (const interv &a, const interv &b) {
    if (a.st == b.st)
        return a.dr < b.dr;
    int sza = a.dr - a.st + 1;
    int szb = b.dr - b.st + 1;

    if (sza > dp[a.st][b.st] && szb > dp[a.st][b.st])
        return les[a.st][b.st];
    return sza < szb;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin.get(sir + 1, 5005);
    int n = strlen(sir + 1);

    int k = 1;
    cin >> k;

    sir[n + 1] = 'a' - 1;
    sir[n + 2] = 'a' - 1;

    int pos = 0;
    for (int i = 0; i <= n + 1; i++) {
        palin[i][i] = palin[i + 1][i] = palin[i + 2][i] = palin[i + 3][i] = 1;

        if (i >= 1 && i <= n) {
            v[++ pos].st = i;
            v[pos].dr = i;
        }
    }

    int j;
    for (int i = n; i >= 1; i--)
        for (j = i + 1; j <= n; j++) {
            if (sir[i] == sir[j]) {
                dp[i][j] = dp[j][i] = (1 + dp[i + 1][j + 1]);
                les[i][j] = (sir[i + dp[i][j]] < sir[j + dp[i][j]]);
                les[j][i] = (sir[i + dp[i][j]] > sir[j + dp[i][j]]);

                palin[i][j] = palin[i + 2][j - 2];

                if (palin[i][j]) {
                    v[++ pos].st = i;
                    v[pos].dr = j;
                }
            }
            else {
                les[i][j] = (sir[i] < sir[j]);
                les[j][i] = (sir[j] < sir[i]);
            }
        }

    nth_element(v + 1, v + k, v + pos + 1);

    int st = v[k].st;
    int dr = v[k].dr;

    for (int i = st; i <= dr; i++)
        cout << sir[i];
    cout << '\n';
    return 0;
}