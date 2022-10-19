#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
vector<pair<int, int> > a[N];

int tin[N], ti;
int s[N];
int u[N];
int d[N];

void dfs(int x, int p)
{
    tin[x] = ++ti;
    if (x != p)
        d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p)
            continue;
        u[a[x][i].second] = h;
        if (x == p)
            s[h] = h;
        else
            s[h] = s[x];
        dfs(h, x);
    }
}

int t[N];
void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, i));
        a[y].push_back(m_p(x, i));
    }
    int maxu = -1, r;
    for (int i = 1; i <= n; ++i)
    {
        if ((int)a[i].size() > maxu)
        {
            maxu = (int)a[i].size();
            r = i;
        }
    }
    dfs(r, r);
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int i;
            scanf("%d", &i);
            ubd(tin[u[i]], -1);
        }
        else if (ty == 2)
        {
            int i;
            scanf("%d", &i);
            ubd(tin[u[i]], 1);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y)
            {
                printf("0\n");
                continue;
            }
            if (tin[x] < tin[y])
                swap(x, y);
            if (y == r)
            {
                if (!qry(tin[s[x]], tin[x]))
                {
                    printf("%d\n", d[x]);
                }
                else
                {
                    printf("-1\n");
                }
                continue;
            }
            if (s[x] == s[y])
            {
                if (!qry(tin[y] + 1, tin[x]))
                {
                    printf("%d\n", d[x] - d[y]);
                }
                else
                {
                    printf("-1\n");
                }
                continue;
            }
            if (!qry(tin[s[x]], tin[x]) && !qry(tin[s[y]], tin[y]))
                printf("%d\n", d[x] + d[y]);
            else
                printf("-1\n");
        }
    }
    return 0;
}