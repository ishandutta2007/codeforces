#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m;
vector<int> a[N];

struct ban
{
    int x, y, z;
};

vector<ban> ans;

bool c[N];
int tin[N], ti;
bool dfs(int x, int p)
{
    c[x] = true;
    tin[x] = ++ti;
    vector<int> v;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
        {
            if (!dfs(h, x))
                v.push_back(h);
        }
        else if (tin[x] < tin[h])
            v.push_back(h);
    }
    if (v.size() % 2 == 0)
    {
        for (int i = 0; i < v.size(); i += 2)
        {
            ans.push_back({v[i], x, v[i + 1]});
        }
        return false;
    }
    else
    {
        for (int i = 0; i < v.size() - 1; i += 2)
        {
            ans.push_back({v[i], x, v[i + 1]});
        }
        ans.push_back({p, x, v.back()});
        return true;
    }
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (m % 2 == 1)
    {
        printf("No solution\n");
        return;
    }
    dfs(1, 1);
    for (int i = 0; i < m / 2; ++i)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}