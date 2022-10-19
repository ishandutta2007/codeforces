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
const int N = 200005;

int n;

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos] ^= 1;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (t[pos] == 0)
        return -1;
    if (l > r)
        return -1;
    if (tl == tr)
    {
        if (t[pos])
            return tl;
        return -1;
    }
    int m = (tl + tr) / 2;
    int u = qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    if (u != -1)
        return u;
    return qry(tl, m, l, min(m, r), pos * 2);
}

char a[N];
int b[N];
int u[N];
int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i)
    {
        scanf(" %c", &a[i]);
        if (a[i] == '-')
        {
            scanf("%d", &b[i]);
            u[b[i]] = i;
        }
    }
    for (int i = 1; i <= n * 2; ++i)
        ubd(1, n * 2, i, 1);

    for (int i = 1; i <= n; ++i)
    {
        int j = qry(1, n * 2, 1, u[i] - 1, 1);
        if (j == -1)
        {
            printf("NO\n");
            return;
        }
        if (a[j] == '-')
        {
            printf("NO\n");
            return;
        }
        ans[j] = i;
        ubd(1, n * 2, u[i], 1);
        ubd(1, n * 2, j, 1);
    }
    printf("YES\n");
    for (int i = 1; i <= n * 2; ++i)
    {
        if (a[i] == '+')
            printf("%d ", ans[i]);
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