#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
struct p
{
    int l, r, use, i;
};
p a[200];
int res[200];
bool operator < (p a, p b)
{
    if (a.l < b.l)
        return true;
    if (a.l == b.l && a.r < b.r)
        return true;
    return false;
}

int main()
{
    int last = 0, n, i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (a[j].l <= last)
                a[j].l = last + 1;
        sort(a, a + n);
        for (j = 0; j < n; j++)
            if (! a[j].use && a[j].l <= a[j].r)
            {
                a[j].use = true;
                res[a[j].i] = a[j].l;
                last = a[j].l;
                break;
            }
    }
    for (i = 0; i < n; i++)
        cout << res[i] << " ";


    return 0;
}