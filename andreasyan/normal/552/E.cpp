#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5005;

int n;
char a[N];

long long p[N], s[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 0; i < n; i += 2)
    {
        int j = i;
        long long u = (a[i] - '0');
        while (j && a[j - 1] == '*')
        {
            u *= (a[j - 2] - '0');
            j -= 2;
        }
        if (j)
            p[i] = u + p[j - 2];
        else
            p[i] = u;
    }
    for (int i = n - 1; i >= 0; i -= 2)
    {
        int j = i;
        long long u = (a[i] - '0');
        while (j < n - 1 && a[j + 1] == '*')
        {
            u *= (a[j + 2] - '0');
            j += 2;
        }
        s[i] = u + s[j + 2];
    }
    long long ans = p[n - 1];
    for (int l = 0; l < n; l += 2)
    {
        for (int r = l; r < n; r += 2)
        {
            if ((!l || a[l - 1] == '+') && (r == n - 1 || a[r + 1] == '+'))
                continue;
            long long yans = 0;
            int i = l;
            while (i <= r)
            {
                long long u = a[i] - '0';
                int j = i;
                while (j < r && a[j + 1] == '*')
                {
                    u *= (a[j + 2] - '0');
                    j += 2;
                }
                yans += u;
                i = j + 2;
            }
            int rr = r;
            while (rr < n - 1 && a[rr + 1] == '*')
            {
                yans *= (a[rr + 2] - '0');
                rr += 2;
            }
            int ll = l;
            while (ll && a[ll - 1] == '*')
            {
                yans *= (a[ll - 2] - '0');
                ll -= 2;
            }
            if (ll)
                yans += p[ll - 2];
            yans += s[rr + 2];
            ans = max(ans, yans);
        }
    }
    printf("%lld\n", ans);
    return 0;
}