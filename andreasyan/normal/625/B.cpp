#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 32;

int n, m;
char a[N], b[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i + m - 1 >= n)
            break;
        bool z = true;
        for (int j = 0; j < m; ++j)
        {
            if (a[i + j] != b[j])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            ++ans;
            a[i + m - 1] = '#';
        }
    }
    cout << ans << endl;
    return 0;
}