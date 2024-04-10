#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;

int n;
char aa[N][N];
char bb[N][N];
char cc[N];

vector<int> a[N * 4], b[N * 4];

vector<int> v;
int c[N * 4];
void dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        if (!c[h])
            dfs1(h);
    }
}

int u[N * 4];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (aa[i] + 1));
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (bb[i] + 1));
    scanf(" %s", (cc + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((bb[i][j] - '0') == (aa[i][j] - '0'))
            {
                if (cc[i] == '1' && cc[j] == '1')
                {
                    a[i + N].push_back(j + N * 3);
                    a[j + N * 3].push_back(i + N);
                    a[-i + N].push_back(-j + N * 3);
                    a[-j + N * 3].push_back(-i + N);
                }
                else if (cc[j] == '1')
                {
                    a[i + N].push_back(-i + N);
                }
                else if (cc[i] == '1')
                {
                    a[j + N * 3].push_back(-j + N * 3);
                }
            }
            else
            {
                if (cc[i] == '1' && cc[j] == '1')
                {
                    a[i + N].push_back(-j + N * 3);
                    a[-j + N * 3].push_back(i + N);
                    a[j + N * 3].push_back(-i + N);
                    a[-i + N].push_back(j + N * 3);
                }
                else if (cc[j] == '1')
                {
                    a[-i + N].push_back(i + N);
                }
                else if (cc[i] == '1')
                {
                    a[-j + N * 3].push_back(j + N * 3);
                }
                else
                {
                    printf("-1\n");
                    return;
                }
            }
        }
    }
    for (int x = 0; x < N * 4; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            b[y].push_back(x);
        }
    }
    for (int i = 0; i < N * 4; ++i)
    {
        if (!c[i])
            dfs(i);
    }
    reverse(v.begin(), v.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < N * 4; ++i)
    {
        if (!c[v[i]])
        {
            ++k;
            dfs1(v[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i + N] == c[-i + N])
        {
            printf("-1\n");
            return;
        }
    }
    for (int j = 1; j <= n; ++j)
    {
        if (c[j + N * 3] == c[-j + N * 3])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 0; i < v.size(); ++i)
        u[v[i]] = i;
    vector<pair<char, int> > ans;
    for (int i = 1; i <= n; ++i)
    {
        if (u[-i + N] < u[i + N])
            ans.push_back(m_p('r', i - 1));
    }
    for (int j = 1; j <= n; ++j)
    {
        if (u[-j + N * 3] < u[j + N * 3])
            ans.push_back(m_p('c', j - 1));
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i].first == 'r')
            printf("row %d\n", ans[i].second);
        else
            printf("col %d\n", ans[i].second);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}