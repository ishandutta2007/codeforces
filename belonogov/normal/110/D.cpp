#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 10;

bool ch(int a)
{
    while (a > 0)
    {
        if (a % 10 != 4 && a % 10 != 7)
            return false;
        a /= 10;
    }
    return true;
}
int a[2000], kol = 0;

long long schetl(int l, int r, int d)
{
    if (l > a[d])
        return 0;
    if (r < a[d - 1])
        return 0;
    int k;
    k = min(a[d], r) - max(a[d - 1] + 1, l);
    if (k >= 0)
        return k + 1;
    else
        return 0;
}

long long schetr(int l, int r, int d)
{
    if (r < a[d])
        return 0;
    if (l > a[d + 1])
        return 0;
    int k;
    k = min(a[d + 1] - 1, r) - max(a[d], l);
    if (k >= 0)
        return k + 1;
    else
        return 0;
}

int main()
{
    int i, uk = 1, k;
    long long res = 0, x, y, sum, d;
    long long pl, pr, vl, vr;
    long double z, res1;
    cin >> pl >> pr >> vl >> vr >> k;
    for (i = 0; i < 1024; i++)
    {
        x = i;
        d = 0;
        while(x > 1)
        {
            d *= 10;
            if (x % 2 == 0)
                d += 4;
            else
                d += 7;
            x /= 2;
        }
        a[kol] = d;
        kol++;
    }
    a[kol] = INF;
    kol++;
    sort(a, a + kol);
    while (uk + k < kol)
    {
        x = schetl(pl, pr, uk);
        y = schetr(vl, vr, uk + k - 1);
        res += x * y;
        x = schetl(vl, vr, uk);
        y = schetr(pl, pr, uk + k - 1);
        res += x * y;
        uk++;
    }
    for (i = 0; i < kol - 1; i++)
        if (a[i] >= pl && a[i] <= pr && a[i] >= vl && a[i] <= vr && k == 1)
            res--;
    sum = (1 + pr - pl) * (vr - vl + 1);
    cout.precision(15);
    res1 = res;
    z = res1 / sum;
    cout << fixed << z;

    return 0;
}