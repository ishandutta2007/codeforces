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

int n;
int b[N];
vector<int> g[N];

int aa[N];
void solv()
{
    /*n = rnf() % 20 + 1;
    for (int i = 1; i <= n; ++i)
        aa[i] = i;
    for (int i = n; i >= 1; --i)
        swap(aa[i], aa[rnf() % i + 1]);
    int kk = rnf() % (n + 1);

    int a1 = 0, a2 = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (aa[i] <= kk)
        {
            b[aa[i]] = a2;
            a1 = aa[i];
        }
        else
        {
            b[aa[i]] = a1;
            a2 = aa[i];
        }
    }

    cout << n << ' ' << kk << endl;
    for (int i = 1; i <= n; ++i)
        cout << aa[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << endl;*/

    cin >> n;
    for (int x = 1; x <= n; ++x)
        cin >> b[x];
    for (int x = 0; x <= n + 1; ++x)
        g[x].clear();

    int k = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (b[x] > x)
            ++k;
    }
    for (int x = 1; x <= n; ++x)
    {
        g[b[x]].push_back(x);
    }

    vector<int> a;
    if (!g[0].empty() && !g[n + 1].empty())
        assert(false);
    int x = -1;
    if (!g[0].empty())
    {
        x = 0;
    }
    if (!g[n + 1].empty())
    {
        x = n + 1;
    }
    assert(x != -1);

    while (1)
    {
        if (1 <= x && x <= n)
            a.push_back(x);
        if (g[x].empty())
            break;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (g[g[x][i]].empty())
                a.push_back(g[x][i]);
        }
        bool z = false;
        for (int i = 0; i < g[x].size(); ++i)
        {
            if (!g[g[x][i]].empty())
            {
                x = g[x][i];
                z = true;
                break;
            }
        }
        if (!z)
            break;
    }

    assert(sz(a) == n);

    cout << k << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
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