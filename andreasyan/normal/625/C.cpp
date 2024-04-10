#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n, k;
int a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int ans = 0;
    int z1 = 1, z2 = n * n;
    for (int i = n; i >= 1; --i)
    {
        for (int j = n; j >= k; --j)
            a[i][j] = z2--;
        for (int j = 1; j < k; ++j)
            a[i][j] = z1++;
        ans += a[i][k];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}