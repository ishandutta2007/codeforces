#include <iostream>

using namespace std;

const int MAXN = 1005;
char c[MAXN][MAXN], diff[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[i][j];
    int ans = 0;
    for(int i = 0; i < m; i++) {
        bool ok = true;
        for(int j = 0; j + 1 < n; j++)
            if(c[j][i] > c[j + 1][i] && !diff[j]) {
                ok = false;
                break;
            }
        if(ok) {
            for(int j = 0; j + 1 < n; j++)
                if(c[j][i] != c[j + 1][i])
                    diff[j] = true;
        }
        else
            ans++;
    }
    cout << ans << '\n';
    return 0;
}