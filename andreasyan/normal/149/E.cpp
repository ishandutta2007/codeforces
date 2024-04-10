#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
char a[N];

int m;
char b[N];

int z[N], pp[N];
void clc()
{
    memset(pp, 0, sizeof pp);
    int j = 0, r = 0;
    for (int i = 1; i < m; ++i)
    {
        z[i] = 0;
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - j]);
        }
        while (b[z[i]] == b[i + z[i]])
        {
            pp[i + z[i]] = z[i] + 1;
            ++z[i];
        }
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
}

int p[N], s[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf(" %s", a);
    n = strlen(a);
    int qq;
    scanf("%d", &qq);
    int ans = 0;
    while (qq--)
    {
        scanf(" %s", b);
        m = strlen(b);
        int mm = m;
        b[m++] = '#';
        for (int i = n - 1; i >= 0; --i)
            b[m++] = a[i];
        reverse(b, b + mm);
        clc();
        m = mm;
        for (int i = 0; i < n; ++i)
            s[i] = pp[(n - i) + m];
        b[m++] = '#';
        for (int i = 0; i < n; ++i)
            b[m++] = a[i];
        reverse(b, b + mm);
        clc();
        m = mm;
        for (int i = 0; i < n; ++i)
            p[i] = pp[i + m + 1];
        for (int i = 1; i < n; ++i)
            p[i] = max(p[i], p[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            s[i] = max(s[i], s[i + 1]);
        for (int i = 0; i < n; ++i)
        {
            if (p[i] + s[i + 1] >= m && p[i] > 0 && s[i + 1] > 0 && m > 1)
            {
                ++ans;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}