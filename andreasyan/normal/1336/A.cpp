#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, k;
vector<int> a[N];

int q[N], d[N];

int qq[N], pp[N];

void dfs(int x, int p)
{
    pp[x] = p;
    q[x] = 1;
    if (x != p)
        d[x] = d[p] + 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        q[x] += q[h];
        ++qq[x];
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1);
    priority_queue<pair<long long, int> > pq;
    for (int i = 1; i <= n; ++i)
    {
        if (qq[i] == 0)
        {
            pq.push(m_p(d[i], i));
        }
    }
    long long ans = 0;
    while (k--)
    {
        pair<long long, int> t = pq.top();
        pq.pop();
        ans += t.first;
        int x = pp[t.second];
        --qq[x];
        if (qq[x] == 0)
        {
            pq.push(m_p(-(q[x] - 1) + d[x], x));
        }
    }
    printf("%I64d\n", ans);
    return 0;
}