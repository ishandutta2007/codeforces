#include <iostream>

using namespace std;

const int MAXN = 5005;
char a[MAXN][MAXN];
int len[MAXN][MAXN], c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '0')
                len[i][j] = 0;
            else if(!j)
                len[i][j] = 1;
            else
                len[i][j] = len[i][j - 1] + 1;
        }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            c[len[j][i]]++;
        for(int j = m; j > 0; j--) {
            if(ans < c[j] * j)
                ans = c[j] * j;
            c[j - 1] += c[j];
        }
        for(int j = 0; j <= m; j++)
            c[j] = 0;
    }
    cout << ans << '\n';
    return 0;
}