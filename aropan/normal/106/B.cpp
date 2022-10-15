#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

const int MAXN = 111;

struct info
{
    int S, R, H, C, I;
};

info a[MAXN];
int n, m;

bool operator<(const info &i, const info &j)
{
    return i.S < j.S;
}

int opr_sort(const info &i, const info &j)
{
    return i.C < j.C;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &a[i].S, &a[i].R, &a[i].H, &a[i].C);
        a[i].I = i;
    }

    sort(a, a + n);
    reverse(a, a + n);

    m = 0;
    for (int i = 1; i < n; i++)
    {
        bool f = false;
        for (int j = 0; j <= m && !f; j++)
            f = a[j].S > a[i].S && a[j].R > a[i].R && a[j].H > a[i].H;

        if (f) continue;
        a[++m] = a[i];
    }
    m++;

    sort(a, a + m, opr_sort);
    printf("%d\n", a[0].I + 1);
    return 0;
}