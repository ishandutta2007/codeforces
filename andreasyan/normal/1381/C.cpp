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
const int N = 100005;

int n, x, y;
int b[N];

int a[N];

void gen()
{
    n = 15;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rnf() % (n + 1) + 1;
        b[i] = rnf() % (n + 1) + 1;
    }

    x = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i])
            ++x;
    }

    map<int, int> mpa, mpb;
    for (int i = 1; i <= n; ++i)
    {
        mpa[a[i]]++;
        mpb[b[i]]++;
    }

    y = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        y += min(mpa[i], mpb[i]);
    }
}

void stg()
{
    int xx = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i])
            ++xx;
    }

    map<int, int> mpa, mpb;
    for (int i = 1; i <= n; ++i)
    {
        mpa[a[i]]++;
        mpb[b[i]]++;
    }

    int yy = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        yy += min(mpa[i], mpb[i]);
    }

    if (!(xx == x && yy == x + y))
    {
        printf("WA\n");
        exit(0);
    }
}

vector<int> v[N];

int q[N];

void solv()
{
    for (int i = 1; i <= n + 1; ++i)
    {
        a[i] = 0;
        v[i].clear();
        q[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        v[b[i]].push_back(i);

    set<pair<int, int> > s;
    for (int i = 1; i <= n + 1; ++i)
        s.insert(m_p(sz(v[i]), i));

    y -= x;
    int m = n - x;
    for (int ii = 0; ii < x; ++ii)
    {
        int x = (--s.end())->se;
        s.erase(--s.end());
        a[v[x].back()] = x;
        v[x].pop_back();
        s.insert(m_p(sz(v[x]), x));
    }

    int u = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (v[i].empty())
        {
            u = i;
            break;
        }
    }

    s.clear();
    for (int i = 1; i <= n + 1; ++i)
    {
        q[i] = sz(v[i]);
    }
    for (int i = 1; i <= n + 1; ++i)
    {
        s.insert(m_p(q[i], i));
    }
    for (int ii = 0; ii < m - y; ++ii)
    {
        int x = (--s.end())->se;
        s.erase(--s.end());
        q[x]--;
        q[u]++;
        s.insert(m_p(q[x], x));
    }

    for (int i = 1; i <= n + 1; ++i)
    {
        if (sz(v[i]) + q[i] > m)
        {
            printf("NO\n");
            return;
        }
    }

    s.clear();
    set<pair<int, int> > sq, sv;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (q[i] && !v[i].empty())
            s.insert(m_p(q[i] + sz(v[i]), i));
        else if (q[i])
            sq.insert(m_p(q[i], i));
        else
            sv.insert(m_p(sz(v[i]), i));
    }

    for (int ii = 0; ii < m; ++ii)
    {
        if (s.size() >= 2)
        {
            int x = (--s.end())->se;
            int y = (--(--s.end()))->se;
            s.erase(m_p(q[x] + sz(v[x]), x));
            s.erase(m_p(q[y] + sz(v[y]), y));

            if (!v[x].empty() && q[y])
            {
                a[v[x].back()] = y;
                v[x].pop_back();
                q[y]--;
            }
            else
            {
                a[v[y].back()] = x;
                v[y].pop_back();
                q[x]--;
            }

            if (q[x] && !v[x].empty())
                s.insert(m_p(q[x] + sz(v[x]), x));
            else if (q[x])
                sq.insert(m_p(q[x], x));
            else
                sv.insert(m_p(sz(v[x]), x));

            if (q[y] && !v[y].empty())
                s.insert(m_p(q[y] + sz(v[y]), y));
            else if (q[y])
                sq.insert(m_p(q[y], y));
            else
                sv.insert(m_p(sz(v[y]), y));
        }
        else if (s.size() == 1)
        {
            int x = (--s.end())->se;
            int y = (--sq.end())->se;
            s.erase(m_p(q[x] + sz(v[x]), x));
            sq.erase(m_p(q[y], y));

            a[v[x].back()] = y;
            v[x].pop_back();
            q[y]--;

            if (q[x] && !v[x].empty())
                s.insert(m_p(q[x] + sz(v[x]), x));
            else if (q[x])
                sq.insert(m_p(q[x], x));
            else
                sv.insert(m_p(sz(v[x]), x));

            sq.insert(m_p(q[y], y));
        }
        else
        {
            int x = (--sv.end())->se;
            int y = (--sq.end())->se;
            sv.erase(m_p(sz(v[x]), x));
            sq.erase(m_p(q[y], y));

            a[v[x].back()] = y;
            v[x].pop_back();
            q[y]--;

            sv.insert(m_p(sz(v[x]), x));
            sq.insert(m_p(q[y], y));
        }
    }

    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 100;

    /*while (tt--)
    {
        gen();
        printf("gen\n");
        printf("%d %d %d\n", n, x, y);
        for (int i = 1; i <= n; ++i)
            printf("%d ", b[i]);
        printf("\n\n");

        solv();
        stg();
    }
    return 0;*/

    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d%d", &n, &x, &y);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}