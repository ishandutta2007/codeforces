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
const int N = 200005;

int n;
vector<int> g[N];

int c[N];
void dfs(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            c[h] = 3 - c[x];
            dfs(h);
        }
    }
}

int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        c[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    c[1] = 1;
    dfs(1);

    int q[3] = {};
    for (int i = 1; i <= n; ++i)
        q[c[i]]++;

    if (q[2] < q[1])
    {
        for (int i = 1; i <= n; ++i)
            c[i] = 3 - c[i];
        swap(q[1], q[2]);
    }

    vector<int> v;
    for (int i = 0; i < 20; ++i)
    {
        if ((q[1] & (1 << i)))
        {
            for (int x = 0; x < (1 << i); ++x)
            {
                v.push_back((x | (1 << i)));
            }
        }
    }
    sort(all(v));

    int j = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 1)
            p[i] = v[j++];
    }

    vector<int> vv;
    for (int i = 1; i <= n; ++i)
    {
        if (!binary_search(all(v), i))
            vv.push_back(i);
    }
    v = vv;

    j = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 2)
            p[i] = v[j++];
    }

    for (int i = 1; i <= n; ++i)
        cout << p[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}