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
const int N = 18;

vector<int> rec(int n)
{
    if (n == 1)
    {
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        return v;
    }

    vector<int> u = rec(n / 2);
    vector<int> v;
    for (int x = 0; x < (1 << n); ++x)
    {
        int p = 0;
        int z = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            if ((x & (1 << i)))
            {
                p ^= (n / 2);
                z |= (1 << i);
            }
        }
        int y = 0;
        for (int i = n / 2; i < n; ++i)
        {
            if ((x & (1 << i)))
                y |= (1 << (i - n / 2));
        }
        v.push_back(p + (u[y] ^ u[z]));
    }

    return v;
}

int n;
vector<int> g[(1 << N)];

int u[(1 << N)];
bool c[(1 << N)];
int ru[(1 << N)];

void solv()
{
    cin >> n;

    /*vector<int> gg = rec(n);
    for (int i = 0; i < (1 << n); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i & (1 << j)))
                cout << '1';
            else
                cout << '0';
        }
        cout << ' ';
        cout << gg[i] << '\n';
    }
    return;*/

    for (int i = 0; i < (1 << n); ++i)
    {
        g[i].clear();
        c[i] = false;
        u[i] = 0;
    }
    for (int i = 0; i < n * (1 << (n - 1)); ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    u[0] = 0;
    c[0] = true;
    for (int i = 0; i < g[0].size(); ++i)
    {
        u[g[0][i]] = (1 << i);
    }
    for (int q = 1; q <= n; ++q)
    {
        vector<int> v;
        for (int x = 0; x < (1 << n); ++x)
        {
            if (c[x])
                continue;
            if (!u[x])
                continue;
            c[x] = true;
            v.push_back(x);
        }
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = 0; j < sz(g[v[i]]); ++j)
            {
                int h = g[v[i]][j];
                if (c[h])
                    continue;
                u[h] |= u[v[i]];
            }
        }
    }
    for (int x = 0; x < (1 << n); ++x)
        ru[u[x]] = x;
    for (int x = 0; x < (1 << n); ++x)
        cout << ru[x] << ' ';
    cout << "\n";

    int nn = n;
    while (nn % 2 == 0)
        nn /= 2;
    if (nn != 1)
    {
        cout << "-1\n";
        return;
    }
    vector<int> v = rec(n);
    for (int i = 0; i < (1 << n); ++i)
        cout << v[u[i]] << ' ';
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