#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int p[MAXN];
long long pref[2][MAXN], suff[2][MAXN];
char c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < 2; i++) {
        pref[i][0] = 0;
        for(int j = 0; j < n; j++)
            pref[i][j + 1] = pref[i][j] + (c[j] == 'A' + i? p[j] : 0);
        suff[i][n] = 0;
        for(int j = n - 1; j >= 0; j--)
            suff[i][j] = suff[i][j + 1] + (c[j] == 'A' + i? p[j] : 0);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, max(pref[0][i] + suff[1][i], pref[1][i] + suff[0][i]));
    cout << ans << '\n';
    return 0;
}