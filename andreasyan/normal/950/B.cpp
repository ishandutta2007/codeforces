#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 1; j <= m; ++j)
        cin >> b[j];
    int ans = 0;
    int i = 0;
    int suma = 0;
    int j = 0;
    int sumb = 0;
    while (1)
    {
        if (suma < sumb)
        {
            suma += a[++i];
        }
        else
        {
            sumb += b[++j];
        }
        if (suma == sumb)
            ++ans;
        if (i == n && j == m)
            break;
    }
    cout << ans << endl;
    return 0;
}