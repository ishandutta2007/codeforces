#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n, k;

bool qry(int x, int y)
{
    if (!(1 <= y && y <= n))
        return true;
    if (!(1 <= x && x <= n))
        return false;
    printf("1 %d %d\n", x, y);
    fflush(stdout);
    char ans[6];
    scanf(" %s", ans);
    return (ans[0] == 'T');
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    int l = 1, r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (qry(m, m + 1))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    int u = l;
    l = u + 1, r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (qry(m, m + 1))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    int u1 = l;
    l = 1, r = u - 1;
    while (l < r)
    {
        int m = (l + r ) / 2;
        if (qry(m, m + 1))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    int u2 = l;
    if (qry(u1, u))
    {
        printf("2 %d %d\n", u, u1);
        fflush(stdout);
    }
    else
    {
        printf("2 %d %d\n", u, u2);
        fflush(stdout);
    }
    return 0;
}