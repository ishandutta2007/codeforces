#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n;

int qry(int i)
{
    int j = i + (n / 2);
    if (j > n)
        j -= n;
    printf("? %d\n", i);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    printf("? %d\n", j);
    fflush(stdout);
    int y;
    scanf("%d", &y);
    return x - y;
}

int main()
{
    scanf("%d", &n);
    if ((n / 2) % 2 == 1)
    {
        printf("! %d\n", -1);
        fflush(stdout);
        return 0;
    }
    int l = 1, r = n;
    while (1)
    {
        int m = (l + r) / 2;
        int u = qry(m);
        if (u == 0)
        {
            printf("! %d\n", m);
            fflush(stdout);
            return 0;
        }
        if (u > 0)
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}