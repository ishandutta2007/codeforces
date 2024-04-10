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
const int N = 102;

int n;

vector<pair<int, int> > v[3];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            v[(i + j) % 2 + 1].push_back(m_p(i, j));
        }
    }
    for (int ii = 0; ii < n * n; ++ii)
    {
        int x;
        cin >> x;

        if (v[1].empty())
        {
            pair<int, int> t = v[2].back();
            v[2].pop_back();

            int u = 1;
            if (u == 1 || u == x)
                ++u;
            if (u == 1 || u == x)
                ++u;
            if (u == 1 || u == x)
                ++u;
            if (u == 1 || u == x)
                ++u;

            cout << u << ' ' << t.fi << ' ' << t.se << endl;
            continue;
        }
        if (v[2].empty())
        {
            pair<int, int> t = v[1].back();
            v[1].pop_back();

            int u = 1;
            if (u == 2 || u == x)
                ++u;
            if (u == 2 || u == x)
                ++u;
            if (u == 2 || u == x)
                ++u;
            if (u == 2 || u == x)
                ++u;

            cout << u << ' ' << t.fi << ' ' << t.se << endl;
            continue;
        }

        int u = 1;
        if (x == u)
            ++u;
        if (x == u)
            ++u;

        pair<int, int> t = v[u].back();
        v[u].pop_back();
        cout << u << ' ' << t.fi << ' ' << t.se << endl;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}