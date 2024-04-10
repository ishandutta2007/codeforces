#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 1003;

int n;
int s[N];
int a[N];
int b[N];

void ka()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void gen()
{
    n = 7;
    for (int i = 1; i <= n; ++i)
        a[i] = (rnf() % 50);
}

void solv0()
{
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] > a[j])
                v.push_back(m_p(i, j));
        }
    }
    sort(all(v));

    int ans = 0;
    do
    {
        for (int i = 1; i <= n; ++i)
            b[i] = a[i];
        for (int i = 0; i < v.size(); ++i)
        {
            swap(b[v[i].fi], b[v[i].se]);
        }
        bool z = true;
        for (int i = 1; i < n; ++i)
        {
            if (!(b[i] <= b[i + 1]))
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            ++ans;
            for (int i = 0; i < v.size(); ++i)
                printf("%d %d\n", v[i].fi, v[i].se);
            printf("\n");
            printf("\n");
        }
    } while (next_permutation(all(v)));
}

vector<int> g[N];

int u[N];

void solv()
{
    for (int i = 1; i <= n; ++i)
    {
        s[i] = a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] > a[j])
                g[i].push_back(j);
        }
    }

    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; ++i)
    {
        vector<pair<int, int> > v;
        v.push_back(m_p(a[i], i));
        for (int j = 0; j < g[i].size(); ++j)
        {
            int h = g[i][j];
            v.push_back(m_p(a[h], h));
        }
        sort(all(v));

        /*if (v[0].fi != b[i])
        {
            printf("%d\n", n);
            for (int i = 1; i <= n; ++i)
            {
                printf("%d ", s[i]);
            }
            printf("\n");
            exit(0);
        }*/

        v.clear();
        v.push_back(m_p(s[i], i));
        for (int j = 0; j < g[i].size(); ++j)
        {
            int h = g[i][j];
            v.push_back(m_p(s[h], h));
        }
        sort(all(v));

        vector<pair<int, int> > vv;
        vv.push_back(m_p(a[i], i));
        for (int j = 0; j < g[i].size(); ++j)
        {
            int h = g[i][j];
            if (h == v[0].se)
                continue;
            vv.push_back(m_p(a[h], h));
        }
        sort(all(vv));

        int k = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j].se == i)
                continue;
            u[vv[k].se] = v[j].se;
            //a[v[j].se] = vv[k].fi;
            ++k;
        }
        int j = i;
        while (1)
        {
            if (j == v[0].se)
                break;
            ans.push_back(m_p(i, u[j]));
            j = u[j];
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        swap(s[ans[i].fi], s[ans[i].se]);
    //for (int i = 1; i <= n; ++i)
    //    assert(b[i] == s[i]);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    /*int tt = 1;
    while (tt--)
    {
        gen();
        solv0();
    }*/
    ka();
    solv();
    return 0;
    int tt = 1000;
    while (tt--)
    {
        gen();
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}