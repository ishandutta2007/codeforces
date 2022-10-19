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
const int N = 200005, S = 320;

int n;
vector<int> a[N];
vector<int> b[N];

int c[N];

void solv()
{
    scanf("%d", &n);

    for (int i = 0; i <= n; ++i)
        a[i].clear();

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            v.push_back(x);
        }
    }

    sort(all(v));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            a[i][j] = lower_bound(all(v), a[i][j]) - v.begin() + 1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (sz(a[i]) <= S)
            continue;
        for (int j = 0; j < sz(a[i]); ++j)
            c[a[i][j]] = 1;
        for (int k = 1; k <= n; ++k)
        {
            if (k == i)
                continue;
            int q = 0;
            for (int j = 0; j < sz(a[k]); ++j)
                q += c[a[k][j]];
            if (q >= 2)
            {
                printf("%d %d\n", i, k);
                for (int j = 0; j < sz(a[i]); ++j)
                    c[a[i][j]] = 0;
                return;
            }
        }
        for (int j = 0; j < sz(a[i]); ++j)
            c[a[i][j]] = 0;
    }

    for (int i = 1; i <= sz(v); ++i)
        b[i].clear();

    for (int i = 1; i <= n; ++i)
    {
        if (sz(a[i]) > S)
            continue;
        for (int j = 0; j < sz(a[i]); ++j)
        {
            b[a[i][j]].push_back(i);
        }
    }

    for (int i = 1; i <= sz(v); ++i)
    {
        for (int j = 0; j < sz(b[i]); ++j)
        {
            int x = b[i][j];
            for (int k = 0; k < a[x].size(); ++k)
            {
                if (a[x][k] == i)
                    continue;
                if (c[a[x][k]])
                {
                    printf("%d %d\n", x, c[a[x][k]]);
                    for (int j = 0; j < sz(b[i]); ++j)
                    {
                        int x = b[i][j];
                        for (int k = 0; k < a[x].size(); ++k)
                        {
                            c[a[x][k]] = 0;
                        }
                    }
                    return;
                }
                c[a[x][k]] = x;
            }
        }
        for (int j = 0; j < sz(b[i]); ++j)
        {
            int x = b[i][j];
            for (int k = 0; k < a[x].size(); ++k)
            {
                c[a[x][k]] = 0;
            }
        }
    }

    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}