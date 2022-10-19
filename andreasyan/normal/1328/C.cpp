#include <bits/stdc++.h>
using namespace std;
const int N = 50004;

int n;
char x[N];
char a[N], b[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", x);
    a[n] = b[n] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x[i] == '1')
        {
            a[i] = '0';
            b[i] = '1';
            for (i = i + 1; i < n; ++i)
            {
                if (x[i] == '0')
                {
                    a[i] = b[i] = '0';
                }
                else if (x[i] == '1')
                {
                    a[i] = '1';
                    b[i] = '0';
                }
                else
                {
                    a[i] = '2';
                    b[i] = '0';
                }
            }
            break;
        }
        if (x[i] == '2')
            a[i] = b[i] = '1';
        else
            a[i] = b[i] = '0';
    }
    printf("%s\n%s\n", a, b);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}