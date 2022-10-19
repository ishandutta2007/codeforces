#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
char a[N][N];
int b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int t[5] = {};
        for (int j = 0; j < n; ++j)
        {
            t[a[j][i] - 'A'] += b[i];
        }
        int maxu = 0;
        for (int j = 0; j < 5; ++j)
            maxu = max(maxu, t[j]);
        ans += maxu;
    }
    cout << ans << endl;
    return 0;
}