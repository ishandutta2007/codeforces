#include <iostream>

using namespace std;
const int MAXN = 20 * 1000 + 5, MAXM = 15;
int a[MAXN][MAXM], c[MAXM], ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ans[x]--;
        c[y]++;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j])
                ans[i] += c[j];
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}