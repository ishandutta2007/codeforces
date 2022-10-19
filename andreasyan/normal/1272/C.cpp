#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
char a[N];
bool c[26];

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", a);
    for (int i = 0; i < k; ++i)
    {
        char x;
        scanf(" %c", &x);
        c[x - 'a'] = true;
    }
    long long ans = 0;
    long long q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!c[a[i] - 'a'])
        {
            ans += (q * (q + 1)) / 2;
            q = 0;
        }
        else
        {
            ++q;
        }
    }
    ans += (q * (q + 1)) / 2;
    printf("%lld\n", ans);
    return 0;
}