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
const int N = 1003;

int n, m;
char a[N][N];

int c[N];

int s, f;
int p[N];

bool dfs(int x)
{
    c[x] = 1;
    for (int h = 1; h <= n; ++h)
    {
        if (a[x][h] == 'a')
        {
            if (c[h] == 1)
            {
                s = h;
                f = x;
                return true;
            }
            else if (c[h] == 0)
            {
                p[h] = x;
                if (dfs(h))
                    return true;
            }
        }
    }
    c[x] = 2;
    return false;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int x = 1; x <= n; ++x)
        scanf(" %s", (a[x] + 1));

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (dfs(x))
        {
            printf("YES\n");
            vector<int> v;
            for (int y = f; y != s; y = p[y])
                v.push_back(y);
            v.push_back(s);
            reverse(all(v));
            int j = 0;
            for (int i = 0; i < m + 1; ++i)
            {
                printf("%d ", v[j]);
                j = (j + 1) % sz(v);
            }
            printf("\n");
            return;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 'a')
                a[i][j] = 'b';
            else if (a[i][j] == 'b')
                a[i][j] = 'a';
        }
    }

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (dfs(x))
        {
            printf("YES\n");
            vector<int> v;
            for (int y = f; y != s; y = p[y])
                v.push_back(y);
            v.push_back(s);
            reverse(all(v));
            int j = 0;
            for (int i = 0; i < m + 1; ++i)
            {
                printf("%d ", v[j]);
                j = (j + 1) % sz(v);
            }
            printf("\n");
            return;
        }
    }


    if (m % 2 == 1)
    {
        printf("YES\n");
        for (int i = 0; i < m + 1; ++i)
        {
            printf("%d ", i % 2 + 1);
        }
        printf("\n");
        return;
    }

    if (n == 2)
    {
        printf("NO\n");
        return;
    }

    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 'a')
                ++q;
        }
        v.push_back(m_p(q, i));
    }
    sort(all(v));

    printf("YES\n");
    if ((m / 2) % 2 == 0)
    {
        for (int i = 0; i < m / 2; ++i)
        {
            if (i % 2 == 0)
                printf("%d ", v[0].se);
            else
                printf("%d ", v.back().se);
        }
        printf("%d ", v[1].se);
        for (int i = 0; i < m / 2; ++i)
        {
            if (i % 2 == 0)
                printf("%d ", v[0].se);
            else
                printf("%d ", v.back().se);
        }
    }
    else
    {
        for (int i = 0; i < m / 2; ++i)
        {
            if (i % 2 == 0)
                printf("%d ", v[0].se);
            else
                printf("%d ", v.back().se);
        }
        printf("%d ", v[sz(v) - 2].se);
        for (int i = 0; i < m / 2; ++i)
        {
            if (i % 2 == 1)
                printf("%d ", v[0].se);
            else
                printf("%d ", v.back().se);
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
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}