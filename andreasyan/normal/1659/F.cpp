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

int n, s;
vector<int> g[N];
int p[N];

bool c[N];

void solv()
{
    cin >> n >> s;
    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        c[x] = false;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
        cin >> p[x];

    int r = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (sz(g[x]) == n - 1)
        {
            r = x;
            break;
        }
    }

    if (!r)
    {
        cout << "Alice\n";
        return;
    }

    if (p[r] != r)
    {
        if (p[r] == s || s == r)
        {
            cout << "Bob\n";
            return;
        }

        for (int x = 1; x <= n; ++x)
        {
            if (p[x] == r)
            {
                swap(p[x], p[r]);
                break;
            }
        }
        s = r;
    }

    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        int x = i;
        while (1)
        {
            c[x] = true;
            if (c[p[x]])
                break;
            ++q;
            x = p[x];
        }
    }

    if (q == 0)
    {
        cout << "Alice\n";
        return;
    }
    if (q == 1)
    {
        if (p[s] == s)
            cout << "Alice\n";
        else
            cout << "Bob\n";
        return;
    }

    if (s == r)
    {
        if (q % 2 == 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    else
    {
        if (q % 2 == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
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