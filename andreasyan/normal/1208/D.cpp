#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1000000009000000009;

int n;
long long a[N];

long long minu[N * 4];
long long laz[N * 4];

priority_queue<int> q;

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        minu[pos] = a[tl];
        laz[pos] = 0;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    laz[pos] = 0;
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

void shi(int pos)
{
    minu[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    minu[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, long long y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

void han(int tl, int tr, int pos)
{
    if (minu[pos])
        return;
    if (tl == tr)
    {
        minu[pos] = INF;
        q.push(tl);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    han(tl, m, pos * 2);
    han(m + 1, tr, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

int ans[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    bil(1, n, 1);
    han(1, n, 1);
    for (int x = 1; x <= n; ++x)
    {
        int i = q.top();
        q.pop();
        ans[i] = x;
        ubd(1, n, i + 1, n, -x, 1);
        if (x == 4)
            cout << "";
        han(1, n, 1);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}