#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n, m;
int a[N];

int ans[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        ans[tl] = y;
        if (y == -1)
            t[pos] = 0;
        else
            t[pos] = 1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2] >= y)
        return qry(tl, m, y, pos * 2);
    return qry(m + 1, tr, y - t[pos * 2], pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        ans[i] = -1;
    for (int ii = 0; ii < n; ++ii)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == -1)
        {
            vector<int> v;
            for (int i = 1; i <= m; ++i)
            {
                if (t[1] < a[i])
                    break;
                v.push_back(qry(1, n, a[i], 1));
            }
            for (int i = 0; i < v.size(); ++i)
                ubd(1, n, v[i], -1, 1);
        }
        else
        {
            if (t[1] == 0)
                ubd(1, n, 1, ty, 1);
            else
                ubd(1, n, qry(1, n, t[1], 1) + 1, ty, 1);
        }
    }
    if (t[1] == 0)
    {
        printf("Poor stack!\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == 0)
            putchar('0');
        else if (ans[i] == 1)
            putchar('1');
    }
    putchar('\n');
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