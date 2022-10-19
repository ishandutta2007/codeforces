#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 105;

int n;
char a[N];

char b[N];

bool c[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    int ans = 0;
    for (char u = 'z'; u >= 'a'; --u)
    {
        while (1)
        {
            bool z = false;
            memset(c, false, sizeof c);
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] == u && (a[i - 1] == a[i] - 1 || a[i + 1] == a[i] - 1))
                {
                    ++ans;
                    c[i] = true;
                    z = true;
                    break;
                }
            }
            if (!z)
                break;
            int m = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (c[i])
                    continue;
                b[++m] = a[i];
            }
            n = m;
            for (int i = 1; i <= n; ++i)
                a[i] = b[i];
            a[n + 1] = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}