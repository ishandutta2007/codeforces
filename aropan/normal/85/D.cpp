#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 333333;

int xx[MAXN];
int x[MAXN];
int l[MAXN], r[MAXN];
long long f[MAXN][5];
int c[MAXN];
int n, m, k;

int modify(int &id, int left, int right, int koff, int value)
{
    if (right < left || value < left || right < value) return 0;

    if (id == 0)
    {
        id = ++k;
        for (int i = 0; i < 5; i++)
            f[id][i] = 0;
        c[id] = 0;
    }


    if (left == right)
    {
        c[id] += koff;
        f[id][2] += koff * xx[value - 1];
        return 0;
    }

    int center = (left + right) / 2;
    modify(l[id], left, center, koff, value);
    modify(r[id], center + 1, right, koff, value);

    for (int i = 0; i < 5; i++)
        f[id][i] = f[l[id]][i] + f[r[id]][(c[l[id]] + i) % 5];

    c[id] = c[l[id]] + c[r[id]];
/*
    printf("%d %d %d %d %d: [%d]", id, left, right, koff, value, c[id]);
    for (int i = 0; i < 5; i++)
        printf(" %I64d", f[id][i]);
    printf("\n");
//*/
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    m = 0;
    for (int i = 0; i < n; i++)
    {
        char s[10];
        scanf("\n%s", s);

        if (strcmp(s, "add") == 0)
        {
            scanf("%d", &x[i]);
            xx[m++] = x[i];
        }
        else
        if (strcmp(s, "del") == 0)
        {
            scanf("%d", &x[i]);
            x[i] = -x[i];
        }
    }

    sort(xx, xx + m);
    m = unique(xx, xx + m) - xx;

    for (int i = 0; i < n; i++)
        if (x[i])
        {
            int v = lower_bound(xx, xx + m, abs(x[i])) - xx + 1;
            x[i] = x[i] < 0? -v : v;
        }

    k = 0;

    int root = ++k;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 0)
            printf("%I64d\n", f[root][0]);
        else       
            modify(root, 1, m, x[i] < 0? -1 : 1, abs(x[i]));
//        printf("\n");
    }


    return 0;
}