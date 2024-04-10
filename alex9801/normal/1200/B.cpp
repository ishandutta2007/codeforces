#include <bits/stdc++.h>
using namespace std;

int arr[110];

void solve()
{
    int n, m, k, i;
    scanf("%d%d%d", &n, &m, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        int d = (arr[i + 1] - k) - arr[i];
        if(d > 0)
        {
            if(m < d)
            {
                puts("NO");
                return;
            }

            m -= d;
        }
        else
            m += min(arr[i], -d);
    }

    puts("YES");
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
        solve();
    return 0;
}