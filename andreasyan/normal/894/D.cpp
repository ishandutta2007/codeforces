#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3000006;

int n, m;
int l[N];

vector<int> v[N];
vector<long long> p[N];

void dfs0(int x)
{
    if (x * 2 <= n)
        dfs0(x * 2);
    if (x * 2 + 1 <= n)
        dfs0(x * 2 + 1);
    v[x].push_back(0);
    for (int i = 0; i < v[x * 2].size(); ++i)
        v[x].push_back(v[x * 2][i] + l[x * 2]);
    for (int i = 0; i < v[x * 2 + 1].size(); ++i)
        v[x].push_back(v[x * 2 + 1][i] + l[x * 2 + 1]);
    sort(v[x].begin(), v[x].end());
    p[x].assign(v[x].size(), 0);
    p[x][0] = v[x][0];
    for (int i = 1; i < v[x].size(); ++i)
        p[x][i] = (p[x][i - 1] + v[x][i]);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 2; i <= n; ++i)
        scanf("%d", &l[i]);
    dfs0(1);
    while (qq--)
    {
        int x, h;
        scanf("%d%d", &x, &h);
        int hh = h;
        long long ans = 0;
        int u = upper_bound(v[x].begin(), v[x].end(), h) - v[x].begin() - 1;
        if (u >= 0)
        {
            ans += ((u + 1) * 1LL * hh);
            ans -= p[x][u];
        }
        int d = 0;
        int xx = x;
        while (1)
        {
            d += l[x];
            h -= l[x];
            x /= 2;
            if (x == 0)
                break;
            if (h <= 0)
                break;
            ans += hh;
            ans -= d;
            int u = upper_bound(v[(xx ^ 1)].begin(), v[(xx ^ 1)].end(), h - l[(xx ^ 1)]) - v[(xx ^ 1)].begin() - 1;
            if (u >= 0)
            {
                ans += ((u + 1) * 1LL * hh);
                ans -= p[(xx ^ 1)][u];
                ans -= ((u + 1) * 1LL * (d + l[(xx ^ 1)]));
            }
            xx = x;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}