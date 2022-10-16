#include <iostream>

using namespace std;

const int MAXN = 105;
int x[MAXN][MAXN], ans[MAXN], used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> x[j][i];
            x[j][i]--;
        }
    for(int i = 0; i < n; i++)
        ans[i] = -1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++)
            if(used[j] >= 0)
                used[j] = -1;
        for(int j = 0; j < n; j++)
            if(ans[j] == -1 && x[i][j] >= 0) {
                if(used[x[i][j]] >= 0) {
                    ans[used[x[i][j]]] = i;
                    ans[j] = i;
                    used[x[i][j]] = -2;
                }
                else if(used[x[i][j]] == -2)
                    ans[j] = i;
                else
                    used[x[i][j]] = j;
            }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << '\n';
    return 0;
}