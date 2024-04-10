#include <iostream>

using namespace std;

const int MAXN = 105, MAXK = 11;
int a[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    if(n > k) {
        int ans = k + 1;
        for(int i = 0; i < n; i++) {
            int s = 0;
            for(int j = 0; j < n; j++) {
                int p = 0, q = 0;
                for(int i0 = 0; i0 < m; i0++)
                    if(a[i][i0] == a[j][i0])
                        q++;
                    else
                        p++;
                s += min(p, q);
            }
            ans = min(ans, s);
        }
        if(ans > k)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    else {
        int ans = k + 1;
        for(int mask = 0; mask < (1 << n); mask++) {
            int s = 0;
            for(int i = 0; i < m; i++) {
                int p = 0, q = 0;
                for(int j = 0; j < n; j++)
                    if((int)((mask & (1 << j)) > 0) == a[j][i])
                        q++;
                    else
                        p++;
                s += min(p, q);
            }
            ans = min(ans, s);
        }
        if(ans > k)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}