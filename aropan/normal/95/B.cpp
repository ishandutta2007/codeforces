#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 111111;

char s[MAXN];
int a[MAXN];

int o[MAXN], z[MAXN];
int l[MAXN];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    gets(s);
    n = strlen(s);
    reverse(s, s + n);
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 4 || a[i] == 7)
        {
            a[i] = a[i] == 4? 0 : 1;
            continue;
        }

        int d = 7 < a[i];
        a[i] = a[i] <= 4 || 7 < a[i]? 0 : 1;

        for (int j = i + 1; j < n; j++)
        {
            d += a[j];
            a[j] = d & 1;
            d >>= 1;
        }

        if (d) n++;

        for (int j = i - 1; j >= 0; j--)
            a[j] = 0;

        break;
    }


    if (n & 1)
    {
        n++;
        for (int i = 0; i < n; i++)
            printf("%d", (i >= n / 2) * 3 + 4);
        printf("\n");
        return 0;
    }



    for (int i = n - 1; i >= 0; i--)
    {
        l[i] = (l[i + 1] + 1) * a[i];
        z[i] = z[i + 1] + (a[i] == 0);
        o[i] = o[i + 1] + (a[i] == 1);
    }


    if (z[0] == o[0])
    {
        for (int i = n - 1; i >= 0; i--)
            printf("%d", a[i] * 3 + 4);
        printf("\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        if (z[i] && z[i] - 1 + l[i] + i >= n / 2 && o[i] + 1 - l[i] + i >= n / 2)
        {
            int d = 1;
            for (int j = i; j < n; j++)
            {
                d += a[j];
                a[j] = d & 1;
                d >>= 1;
            }

            for (int j = 0; j < i; j++)
                a[j] = j < n / 2 - (o[i] + 1 - l[i]);

            for (int i = n - 1; i >= 0; i--)
                printf("%d", a[i] * 3 + 4);
            printf("\n");
            return 0;
        }

    n += 2;
    for (int i = 0; i < n; i++)
        printf("%d", (i >= n / 2) * 3 + 4);
    printf("\n");
    return 0;
}