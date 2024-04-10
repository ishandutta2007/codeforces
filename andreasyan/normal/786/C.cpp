#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 8000006;

int n;
int a[N];

int z;
int ll[M], rr[M];
int t[M];

int ubd(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++z;
    ll[ypos] = ll[pos];
    rr[ypos] = rr[pos];
    t[ypos] = t[pos];
    if (tl == tr)
    {
        t[ypos] = y;
        return ypos;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
    {
        ll[ypos] = ubd(tl, m, x, y, ll[pos]);
    }
    else
    {
        rr[ypos] = ubd(m + 1, tr, x, y, rr[pos]);
    }
    t[ypos] = t[ll[ypos]] + t[rr[ypos]];
    return ypos;
}

int qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        return tl;
    }
    int m = (tl + tr) / 2;
    if (t[rr[pos]] >= y)
        return qry(m + 1, tr, y, rr[pos]);
    return qry(tl, m, y - t[rr[pos]], ll[pos]);
}

int c[N];
int u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[a[i]])
            u[i] = ubd(1, n, i, 1, u[i - 1]);
        else
        {
            u[i] = ubd(1, n, c[a[i]], 0, u[i - 1]);
            u[i] = ubd(1, n, i, 1, u[i]);
        }
        c[a[i]] = i;
    }
    for (int k = 1; k <= n; ++k)
    {
        int ans = 0;
        int s = n;
        while (s)
        {
            ++ans;
            if (t[u[s]] <= k)
                break;
            else
                s = qry(1, n, k + 1, u[s]);
        }
        printf("%d ", ans);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}