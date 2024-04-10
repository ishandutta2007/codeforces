#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int q[N];
int s[N];

int main()
{
    scanf("%d%d", &n, &a[0]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        q[a[i]]++;
        if (s[a[i]] == 0)
            s[a[i]] = i;
    }
    int maxu = 0;
    int qq = 0;
    int ans = n;
    for (int i = 1; i <= n; ++i)
    {
        if (i == s[a[i]])
        {
            qq += q[a[i]];
            maxu = max(maxu, q[a[i]]);
        }
        --qq;
        if (qq == 0)
        {
            ans -= maxu;
            maxu = 0;
        }
    }
    cout << ans << endl;
    return 0;
}