#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, m = 100000;

int n, qq;
int a[N];

int t[N * 4];

void shi(int pos)
{
    if (t[pos] == -2)
    {
        if (t[pos * 2] % 2 == 0)
            ++t[pos * 2];
        else
            --t[pos * 2];
        if (t[pos * 2 + 1] % 2 == 0)
            ++t[pos * 2 + 1];
        else
            --t[pos * 2 + 1];
        t[pos] = -1;
    }
    else if (t[pos] == -1)
        return;
    else
    {
        t[pos * 2] = t[pos];
        t[pos * 2 + 1] = t[pos];
        t[pos] = -1;
    }
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (y == 1)
        {
            if (t[pos] % 2 == 0)
                ++t[pos];
            else
                --t[pos];
        }
        else
        {
            t[pos] = y;
        }
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    else
        return qry(m + 1, tr, x, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    while (qq--)
    {
        char ty;
        int x;
        scanf(" %c%d", &ty, &x);
        if (ty == '<')
        {
            if (x <= 0)
                ubd(0, m, -(x - 1), m, 2, 1);
            else
            {
                ubd(0, m, 0, x - 1, 1, 1);
                ubd(0, m, x, m, 2, 1);
            }
        }
        else
        {
            if (x >= 0)
                ubd(0, m, (x + 1), m, 3, 1);
            else
            {
                ubd(0, m, 0, -(x + 1), 1, 1);
                ubd(0, m, -x, m, 3, 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int u = qry(0, m, abs(a[i]), 1);
        if (u == 0)
            printf("%d ", a[i]);
        else if (u == 1)
            printf("%d ", -a[i]);
        else if (u == 2)
            printf("%d ", abs(a[i]));
        else if (u == 3)
            printf("%d ", -abs(a[i]));
        else
            assert(false);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}