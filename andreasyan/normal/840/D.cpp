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
const int N = 300005;

int n, m;
int a[N];
vector<int> v[N];

struct ban
{
    int i;
    int l, r, k;
};
ban b[N];

vector<int> uq[N * 4];

void ave(int tl, int tr, int l, int r, int i, int pos)
{
    if (tl == tr)
    {
        uq[pos].push_back(i);
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
    {
        ave(tl, m, l, r, i, pos * 2);
        return;
    }
    if (l > m)
    {
        ave(m + 1, tr, l, r, i, pos * 2 + 1);
        return;
    }
    uq[pos].push_back(i);
}

int ans[N];

int q[N];

set<pair<int, int> > s[N];

void solvv(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    for (int i = m + 1; i <= tr; ++i)
    {
        if (i > m + 1)
            s[i] = s[i - 1];
        else
            s[i].clear();
        if (s[i].find(m_p(q[a[i]], a[i])) != s[i].end())
            s[i].erase(m_p(q[a[i]], a[i]));
        ++q[a[i]];
        s[i].insert(m_p(q[a[i]], a[i]));
        if (s[i].size() > 5)
            s[i].erase(s[i].begin());
    }
    for (int i = m + 1; i <= tr; ++i)
        q[a[i]] = 0;
    for (int i = m; i >= tl; --i)
    {
        if (i < m)
            s[i] = s[i + 1];
        else
            s[i].clear();
        if (s[i].find(m_p(q[a[i]], a[i])) != s[i].end())
            s[i].erase(m_p(q[a[i]], a[i]));
        ++q[a[i]];
        s[i].insert(m_p(q[a[i]], a[i]));
        if (s[i].size() > 5)
            s[i].erase(s[i].begin());
    }
    for (int i = m; i >= tl; --i)
        q[a[i]] = 0;
    for (int ii = 0; ii < uq[pos].size(); ++ii)
    {
        int i = uq[pos][ii];
        int l = b[i].l;
        int r = b[i].r;
        int k = b[i].k;
        ans[i] = N;
        for (auto it = s[r].begin(); it != s[r].end(); ++it)
        {
            int x = it->se;
            int q = upper_bound(all(v[x]), r) - lower_bound(all(v[x]), l);
            if (q > (r - l + 1) / k)
                ans[i] = min(ans[i], x);
        }
        for (auto it = s[l].begin(); it != s[l].end(); ++it)
        {
            int x = it->se;
            int q = upper_bound(all(v[x]), r) - lower_bound(all(v[x]), l);
            if (q > (r - l + 1) / k)
                ans[i] = min(ans[i], x);
        }
        if (ans[i] == N)
            ans[i] = -1;
    }
    if (tl == tr)
        return;
    solvv(tl, m, pos * 2);
    solvv(m + 1, tr, pos * 2 + 1);
}

void kar()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
    {
        b[i].i = i;
        scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].k);
    }
}

void gen()
{
    n = 200;
    for (int i = 1; i <= n; ++i)
        a[i] = rnd() % 7 + 1;
    m = 0;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            for (int k = 2; k <= 5; ++k)
            {
                b[m].i = m;
                b[m].l = l;
                b[m].r = r;
                b[m].k = k;
                m++;
            }
        }
    }
}

int stg0(int l, int r, int k)
{
    for (int x = 1; x <= n; ++x)
        q[x] = 0;
    int ans = N;
    for (int i = l; i <= r; ++i)
    {
        ++q[a[i]];
    }
    for (int x = 1; x <= n; ++x)
    {
        if (q[x] > (r - l + 1) / k)
            ans = min(ans, x);
    }
    if (ans == N)
        ans = -1;
    return ans;
}

void solv()
{
    //gen();
    kar();
    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        q[i] = 0;
    }
    /*for (int i = 1; i <= n * 5; ++i)
        uq[i].clear();*/
    for (int i = 0; i < m; ++i)
    {
        ave(1, n, b[i].l, b[i].r, i, 1);
    }
    for (int i = 1; i <= n; ++i)
        v[a[i]].push_back(i);
    solvv(1, n, 1);
    //printf("Wrong = %d\n", ans[0]);
    //printf("Right = %d\n", stg0(b[0].l, b[0].r, b[0].k));
    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);
    return;
    for (int i = 0; i < m; ++i)
    {
        if (ans[i] != stg0(b[i].l, b[i].r, b[i].k))
        {
            printf("WA\n");
            printf("%d 1\n", n);
            for (int i = 1; i <= n; ++i)
                printf("%d ", a[i]);
            printf("\n");
            printf("%d %d %d\n", b[i].l, b[i].r, b[i].k);
            exit(0);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}