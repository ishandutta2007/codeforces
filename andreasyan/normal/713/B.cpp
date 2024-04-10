#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;

int xx11 = 1, yy11 = 1, xx12 = 5, yy12 = 5;
int xx21 = 3, yy21 = 4, xx22 = 3, yy22 = 5;

int qry(int x1, int y1, int x2, int y2)
{
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int q = 0;
    scanf("%d", &q);
    return q;
    if (x1 <= xx11 && xx12 <= x2 && y1 <= yy11 && yy12 <= y2)
        ++q;
    if (x1 <= xx21 && xx22 <= x2 && y1 <= yy21 && yy22 <= y2)
        ++q;
    return q;
}

int x11, y11, x12, y12;

void solv1()
{
    int l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, 1, m, n) >= 1)
        {
            x12 = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    l = 1, r = x12;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(m, 1, x12, n) >= 1)
        {
            x11 = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, 1, n, m) >= 1)
        {
            y12 = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    l = 1, r = y12;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, m, n, y12) >= 1)
        {
            y11 = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
}

int x21, y21, x22, y22;

void solv2()
{
    int l = 1, r = n;
    int u = 2;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, 1, m, n) >= u)
        {
            x22 = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    l = 1, r = x22;
    u = 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(m, 1, x22, n) >= u)
        {
            x21 = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (x21 == x11)
    {
        l = 1, r = x22;
        u = 2;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(m, 1, x22, n) >= u)
            {
                x21 = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }
    l = 1, r = n;
    u = 2;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, 1, n, m) >= u)
        {
            y22 = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    l = 1, r = y22;
    u = 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, m, n, y22) >= u)
        {
            y21 = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (y21 == y11)
    {
        l = 1, r = y22;
        u = 2;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(1, m, n, y22) >= u)
            {
                y21 = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    solv1();
    solv2();
    if (!qry(x11, y11, x12, y12) || !qry(x21, y21, x22, y22))
    {
        swap(x11, x21);
        swap(x12, x22);
    }
    printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
    fflush(stdout);
    return 0;
}