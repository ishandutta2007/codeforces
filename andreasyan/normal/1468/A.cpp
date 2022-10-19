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
const int N = 500005;

int n;
int a[N];

int z;
int t[N * 22];
int ul[N * 22], ur[N * 22];

int ubd(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++z;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];

    if (tl == tr)
    {
        t[ypos] = y;
        return ypos;
    }

    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, y, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, y, ur[pos]);
    t[ypos] = max(t[ul[ypos]], t[ur[ypos]]);
    return ypos;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), ul[pos]),
               qry(m + 1, tr, max(m + 1, l), r, ur[pos]));
}

int u[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    z = 0;

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        int j = 0;
        if (!s.empty())
            j = s.top();
        s.push(i);

        int dp = qry(1, n, 1, a[i], u[i - 1]) + 1;
        if (j)
            dp = max(dp, qry(1, n, 1, a[i], u[j - 1]) + 2);

        u[i] = ubd(1, n, a[i], dp, u[i - 1]);
    }

    printf("%d\n", qry(1, n, 1, n, u[n]));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}