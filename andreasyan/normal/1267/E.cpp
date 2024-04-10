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

int m, n;
int a[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }

    int ans = m;
    for (int i = 1; i < n; ++i)
    {
        vector<pair<int, int> > v;
        for (int u = 1; u <= m; ++u)
        {
            v.push_back(m_p(a[u][i] - a[u][n], u));
        }

        sort(all(v));
        reverse(all(v));

        int s = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            s += v[i].fi;
            if (s < 0)
                break;

            ans = min(ans, sz(v) - i - 1);
        }
    }

    for (int i = 1; i < n; ++i)
    {
        vector<pair<int, int> > v;
        for (int u = 1; u <= m; ++u)
        {
            v.push_back(m_p(a[u][i] - a[u][n], u));
        }

        sort(all(v));
        reverse(all(v));

        int s = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            s += v[i].fi;
            if (s < 0)
                break;

            if (ans == sz(v) - i - 1)
            {
                cout << ans << "\n";
                for (int j = i + 1; j < sz(v); ++j)
                    cout << v[j].se << ' ';
                cout << "\n";
                return;
            }
        }
    }

    assert(ans == m);
    cout << ans << "\n";
    for (int i = 1; i <= m; ++i)
        cout << i << ' ';
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}