#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, m;
int a[N], b[N];

int main()
{
    //cin >> n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++ i)
        //cin >> a[i];
        scanf("%d",&a[i]);
    //cin >> m;
    scanf("%d",&m);
    for (int i = 0; i < m; ++ i)
        //cin >> b[i];
        scanf("%d",&b[i]);
    int i = 0, j = 0;
    long long suma = 0, sumb = 0;
    int ans = 0;
    while (1)
    {
        if (i == n && j == m)
            break;
        else if (i == n)
        {
            sumb += b[j];
            ++ j;
        }
        else if (j == m)
        {
            suma += a[i];
            ++ i;
        }
        else if (suma < sumb)
        {
            suma += a[i];
            ++ i;
        }
        else if (suma == sumb)
        {
            ++ ans;
            suma += a[i];
            ++ i;
        }
        else
        {
            sumb += b[j];
            ++ j;
        }
    }
    if (suma == sumb)
        cout << ans << endl;
    else
        cout << "-1" << endl;
    return 0;
}