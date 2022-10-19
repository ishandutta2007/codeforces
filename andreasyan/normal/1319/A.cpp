#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;

int n;
int a[N], b[N];

int p[N];
bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
            p[i] = x;
        else
            p[i] = 1;
    }
    int ansa = 0, ansb = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
            ansa += p[i];
        if (b[i] == 1)
            ansb += p[i];
    }
    return ansa > ansb;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int x = 1; x <= 20000; ++x)
    {
        if (stg(x))
        {
            printf("%d\n", x);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}