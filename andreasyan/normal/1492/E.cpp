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
const int N = 200025, INF = 1000000009;

int n, m;
int** a;

int ans[N];
bool stg()
{
    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] != ans[j])
                ++q;
        }
        if (q > 2)
            return false;
    }
    return true;
}

int qq;
int q[N];

void ave(int x)
{
    ++q[x];
    if (q[x] == m - 2)
        ++qq;
}
void han(int x)
{
    if (q[x] == m - 2)
        --qq;
    --q[x];
}

bool stg1()
{
    qq = 0;
    memset(q, 0, sizeof q);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == ans[j])
                ave(i);
        }
    }

    for (int j = 1; j <= m; ++j)
    {
        map<int, vector<int> > mp;
        for (int i = 1; i <= n; ++i)
        {
            mp[a[i][j]].push_back(i);
            if (a[i][j] == ans[j])
                han(i);
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            vector<int> v = it->se;
            for (int i = 0; i < sz(v); ++i)
                ave(v[i]);
            if (qq == n)
            {
                ans[j] = a[v[0]][j];
                printf("Yes\n");
                for (int j = 1; j <= m; ++j)
                    printf("%d ", ans[j]);
                printf("\n");
                return true;
            }
            for (int i = 0; i < sz(v); ++i)
                han(v[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] == ans[j])
                ave(i);
        }
    }
    return false;
}

void solv()
{
    scanf("%d%d", &n, &m);
    a = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
        a[i] = new int[m + 5];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    if (m == 1)
    {
        printf("Yes\n");
        printf("1\n");
        return;
    }
    if (m == 2)
    {
        printf("Yes\n");
        printf("1 1\n");
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        int q = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] != a[1][j])
                ++q;
        }
        if (q <= 2)
            continue;
        if (q > 4)
        {
            printf("No\n");
            return;
        }
        if (q == 4)
        {
            vector<int> v;
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] != a[1][j])
                    v.push_back(j);
            }
            for (int j = 0; j < sz(v); ++j)
            {
                for (int k = j + 1; k < sz(v); ++k)
                {
                    for (int j = 1; j <= m; ++j)
                        ans[j] = a[1][j];
                    ans[v[j]] = a[i][v[j]];
                    ans[v[k]] = a[i][v[k]];
                    if (stg())
                    {
                        printf("Yes\n");
                        for (int j = 1; j <= m; ++j)
                            printf("%d ", ans[j]);
                        return;
                    }
                }
            }
            printf("No\n");
            return;
        }
        else if (q == 3)
        {
            vector<int> v;
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] != a[1][j])
                    v.push_back(j);
            }
            for (int j = 0; j < sz(v); ++j)
            {
                for (int j = 1; j <= m; ++j)
                    ans[j] = a[1][j];
                ans[v[j]] = a[i][v[j]];
                if (stg1())
                {
                    assert(stg());
                    return;
                }
            }
            printf("No\n");
            return;
        }
        assert(false);
    }

    printf("Yes\n");
    for (int j = 1; j <= m; ++j)
        printf("%d ", a[1][j]);
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