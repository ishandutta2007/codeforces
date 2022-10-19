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

int n, m, k;
vector<int> a[N];

vector<int> v[2];
void dfs0(int x, int p, int z)
{
    v[z].push_back(x);
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        dfs0(h, x, (z ^ 1));
    }
}

bool c[N];

int dfs(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (h == p)
            continue;
        if (!c[h])
        {
            int u = dfs(h, x);
            if (u)
                return u;
        }
        else
            return x;
    }
    return 0;
}

int p[N];
int d[N];
int f[N];

vector<int> bfs(int s)
{
    memset(c, false, sizeof c);
    queue<int> q;
    q.push(s);
    c[s] = true;
    int minu = N;
    int xx, yy;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                c[h] = true;
                p[h] = x;
                d[h] = d[x] + 1;
                if (x != s)
                    f[h] = f[x];
                else
                    f[h] = h;
                q.push(h);
            }
            else
            {
                if (x != s && h != s)
                {
                    if (f[h] != f[x])
                    {
                        if (d[x] + d[h] < minu)
                        {
                            minu = d[x] + d[h];
                            xx = x;
                            yy = h;
                        }
                    }
                }
            }
        }
    }
    vector<int> v;
    for (int i = xx; i != s; i = p[i])
        v.push_back(i);
    vector<int> v1;
    for (int i = yy; i != s; i = p[i])
        v1.push_back(i);
    reverse(all(v1));
    v.push_back(s);
    for (int i = 0; i < v1.size(); ++i)
        v.push_back(v1[i]);
    return v;
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (m == n - 1)
    {
        dfs0(1, 1, 0);
        if (v[1].size() > v[0].size())
            swap(v[0], v[1]);
        printf("1\n");
        for (int i = 0; i < k / 2 + k % 2; ++i)
            printf("%d ", v[0][i]);
        printf("\n");
        return;
    }
    int s = dfs(1, -1);
    vector<int> v = bfs(s);
    if (v.size() <= k)
    {
        printf("2\n");
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }
    vector<int> vv;
    for (int i = 0; i < v.size(); i += 2)
        vv.push_back(v[i]);
    v = vv;
    printf("1\n");
    for (int i = 0; i < k / 2 + k % 2; ++i)
        printf("%d ", v[i]);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}