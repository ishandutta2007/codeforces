#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 10, logn = 20, inf = 2e5 + 10;
int L[maxn * logn], R[maxn * logn], sum[maxn * logn];
int root[maxn];
int sz = 1, rt = 1;

int copy(int v, int &u)
{
    L[sz] = L[v];
    R[sz] = R[v];
    sum[sz] = sum[v];
    return u = sz++;
}

void add(int x, int v = root[rt - 1], int l = 0, int r = +inf)
{
    if(r - l == 1)
    {
        sum[v]++;
        return;
    }
    int m = (l + r) >> 1;
    if(x < m)
        add(x, copy(L[v], L[v]), l, m);
    else
        add(x, copy(R[v], R[v]), m, r);
    sum[v] = sum[L[v]] + sum[R[v]];
}

void push(int x)
{
    copy(root[rt - 1], root[rt]);
    rt++;
    add(x);
}

int get(int a, int b, int v, int l = 0, int r = +inf)
{
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l || !v)
        return 0;
    int m = (l + r) >> 1;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r);
}

int cnt(int l, int r, int x)
{
    return get(0, x, root[r - 1]) - get(0, x, root[l - 1]);
}
int x[maxn], y[maxn];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &x[i]),
        y[i] = x[i];
    sort(y, y + n);
    for(int i = 0; i < n; i++)
    {
        x[i] = lower_bound(y, y + n, x[i]) - y;
        push(x[i]);
    }
    int ans[n];
    memset(ans, 0, sizeof(ans));
    for(int k = 1; k < n; k++)
        for(int i = 1; k * (i - 1) + 2 <= n; i++)
            ans[k - 1] += cnt(k * (i - 1) + 2 , min(n + 1, k * i + 2), x[i - 1]);
    for(int i = 0; i < n - 1; i++)
        printf("%d ", ans[i]);
}