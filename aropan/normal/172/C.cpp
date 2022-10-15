#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, m;
int x[MAXN], t[MAXN];
int a[MAXN];
int ans[MAXN];


bool opr_sort(const int &i, const int &j)
{
    return x[i] < x[j];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &t[i], &x[i]);
        a[i] = i;
    }

    int curr = 0;
    for (int i = 0; i < n; i += m)
    {
        int j = min(i + m, n);
        sort(a + i, a + j, opr_sort);
        curr = max(curr, t[j - 1]);
        int k = i;
        while (k < j)
        {
            curr += x[a[k]] - ((k == i)? 0 : x[a[k - 1]]);
            int l = k;
            while (l < j && x[a[k]] == x[a[l]]) ans[a[l++]] = curr;
            curr += (l - k) / 2 + 1;
            k = l;
        }
        curr += x[a[j - 1]];
    }

    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}