#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
 
int n, m;
char a[N], b[N];
 
void solv()
{
    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    reverse(a, a + n);
    reverse(b, b + m);
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
        {
            x = i;
            break;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (b[i] == '1')
        {
            y = i;
            break;
        }
    }
    int i = 0, j = 0;
    int ans = 0;
    while (1)
    {
        if (i == n || j == m)
            break;
        if (a[i] == '1' && b[j] == '1')
            break;
        if (a[i] == '1' && b[j] == '0')
        {
            ++i;
            ++j;
            continue;
        }
        if (a[i] == '0' && b[j] == '1')
        {
            ++i;
            ++ans;
            continue;
        }
        if (a[i] == '0' && b[j] == '0')
        {
            ++i;
            ++j;
            continue;
        }
    }
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}