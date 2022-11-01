#include <bits/stdc++.h>

using namespace std;

int n, l[600], r[600], f[600][600];
char ans[1200];

void rep(int l, int r, int L)
{
    if(f[l][r] == -1) { cout << "IMPOSSIBLE"; exit(0); }
    int d = f[l][r];
    ans[L] = '(';
    ans[L + d] = ')';
    if(d != 1) rep(l + 1, l + d/2, L + 1);
    if(d != 2 * (r - l + 1) - 1) rep(l + d/2 + 1, r, L + d + 1);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i], f[i][i] = (l[i] == 1 ? 1 : -1);
    for(int len = 2; len <= n; len++)
        for(int i = 0; i + len <= n; i++)
        {
            int j = i + len - 1;
            f[i][j] = -1;
            for(int d = l[i]; d <= min(2 * len - 1, r[i]); d++)
            {
                if(!(d & 1)) continue;
                if(d != 1 && f[i + 1][i + d/2] == -1) continue;
                if(d != 2 * len - 1 && f[i + d/2 + 1][j] == -1) continue;
                f[i][j] = d;
                break;
            }
        }
    rep(0, n - 1, 0);
    for(int i = 0; i < 2 * n; i++) cout << ans[i];
}