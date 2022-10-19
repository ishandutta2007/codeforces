#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

int p[N], s[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (i > 1 && a[i - 1] == 'v' && a[i - 2] == 'v')
            ++p[i];
    }
    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1];
        if (a[i - 1] == 'v' && a[i] == 'v')
            s[i]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] == 'o')
        {
            ans += (p[i] * 1LL * s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}