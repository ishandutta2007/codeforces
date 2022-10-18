#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, w, h;
    cin >> c >> w >> h;
    int A[w + 1][w + 1];
    memset(A, 0, sizeof(A));
    for(int i = 1; i <= w; i++)
        A[i][i - 1] = h;
    fill(A[0], A[0] + w + 1, 1);
    int B[w + 1][w + 1];
    memset(B, 0, sizeof(B));
    for(int i = 0; i <= w; i++)
        B[i][i] = 1;
    int C[w + 1][w + 1];
    for(int i = 1; i <= c; i *= 2)
    {
        if(c & i)
        {
            memset(C, 0, sizeof(C));
            for(int i = 0; i <= w; i++)
                for(int j = 0; j <= w; j++)
                    for(int k = 0; k <= w; k++)
                    {
                        C[i][j] += 1LL * A[i][k] * B[k][j] % mod;
                        if(C[i][j] >= mod)
                            C[i][j] -= mod;
                    }
            memcpy(B, C, sizeof(C));
        }
        memset(C, 0, sizeof(C));
        for(int i = 0; i <= w; i++)
            for(int j = 0; j <= w; j++)
                for(int k = 0; k <= w; k++)
                {
                    C[i][j] += 1LL * A[i][k] * A[k][j] % mod;
                    if(C[i][j] >= mod)
                        C[i][j] -= mod;
                }
        memcpy(A, C, sizeof(C));
    }
    int ans = 0;
    for(int i = 0; i <= w; i++)
    {
        ans += B[i][0];
        if(ans >= mod)
            ans -= mod;
    }
    cout << ans << "\n";
	return 0;
}