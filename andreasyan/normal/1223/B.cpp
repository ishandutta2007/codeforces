#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N], b[N];

bool aa[26], bb[26];
bool solv()
{
    scanf(" %s %s", a, b);
    n = strlen(a);
    memset(aa, false, sizeof aa);
    memset(bb, false, sizeof bb);
    for (int i = 0; i < n; ++i)
        aa[a[i] - 'a'] = true;
    for (int i = 0; i < n; ++i)
        bb[b[i] - 'a'] = true;
    for (int i = 0; i < 26; ++i)
    {
        if (aa[i] && bb[i])
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