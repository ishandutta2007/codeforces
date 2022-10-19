#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};
 
int n, m;
long long k;
int a[N][N];
 
vector<pair<int, pair<int, int> > > v;
 
int p[N * N], q[N * N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    if (x == y)
        return;
    p[x] = y;
    q[y] += q[x];
}
 
int qq;
int b[N][N];
void dfs(int x, int y, int z)
{
    if (qq == 0)
        return;
    --qq;
    b[x][y] = z;
    for (int i = 0; i < 4; ++i)
    {
        int hx = x + xx[i];
        int hy = y + yy[i];
        if (hx >= 1 && hx <= n && hy >= 1 && hy <= m)
        {
            if (a[hx][hy] >= z && !b[hx][hy])
            {
                dfs(hx, hy, z);
            }
        }
    }
}
 
int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            v.push_back(m_p(a[i][j], m_p(i, j)));
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[(i - 1) * m + j] = (i - 1) * m + j;
            q[(i - 1) * m + j] = 1;
        }
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int x = v[i].second.first;
        int y = v[i].second.second;
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (hx >= 1 && hx <= n && hy >= 1 && hy <= m)
            {
                if (a[hx][hy] >= a[x][y])
                {
                    kpc((x - 1) * m + y, (hx - 1) * m + hy);
                }
            }
        }
        if (k % a[x][y] == 0)
        {
            if (q[fi((x - 1) * m + y)] >= (k / a[x][y]))
            {
                qq = (k / a[x][y]);
                dfs(x, y, a[x][y]);
                printf("YES\n");
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <= m; ++j)
                    {
                        printf("%d ", b[i][j]);
                    }
                    printf("\n");
                }
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}