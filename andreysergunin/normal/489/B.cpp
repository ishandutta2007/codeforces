#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a[1000], b[1000], ans, p[1000], i, j;
    bool f;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    ans = 0;
    for (i = 0; i < m; i++)
        p[i] = 0;
    for (i = 0; i < n; i++)
    {
        f = true;
        for (j = 0; j < m; j++)
        {
            if (f && abs(a[i] - b[j]) <= 1 && p[j] == 0)
            {
                p[j] = 1;
                f = false;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}