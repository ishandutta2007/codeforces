#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];
int m;
char b[N];

int q[26], qq[26];
bool solv()
{
    scanf(" %s", a);
    scanf(" %s", b);
    n = strlen(a);
    m = strlen(b);
    memset(q, 0, sizeof q);
    for (int i = 0; i < n; ++i)
    {
        q[a[i] - 'a']++;
    }
    for (int l = 0; l <= m - n; ++l)
    {
        int r = l + n - 1;
        memset(qq, 0, sizeof qq);
        for (int i = l; i <= r; ++i)
            qq[b[i] - 'a']++;
        bool z = true;
        for (int i = 0; i < 26; ++i)
        {
            if (q[i] != qq[i])
            {
                z = false;
                break;
            }
        }
        if (z)
            return true;
    }
    return false;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}