/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    vector <int> res(n, n);
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (!a[i])
        {
            last = i;
        }
        if (last != -1)
        {
            res[i] = min(res[i], i - last);
        }
    }
    reverse(a.begin(), a.end());
    last = -1;
    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            last = i;
        }
        if (last != -1)
        {
            res[n - 1 - i] = min(res[n - 1 - i], i - last);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
}