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

int n, m;
int a[N];
int b[N];

bool c[N];

void solv()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        c[i] = false;
    vector<pair<int, pair<int, int> > > vv;

    int ans1 = 1, ans2 = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[j];
            b[j] = a[j];
        }

        sort(b + 1, b + m + 1);

        vector<int> v;
        for (int j = 1; j <= m; ++j)
        {
            if (a[j] != b[j])
            {
                v.push_back(j);
            }
        }

        if (v.empty())
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[j] != a[j - 1])
                {
                    vv.push_back(m_p(i, m_p(j, j)));
                }
                else
                {
                    vv.back().se.se++;
                }
            }
        }
        else
        {
            c[i] = true;
            if (sz(v) > 2)
            {
                ans1 = ans2 = 0;
            }
            else if (ans1 == 1 && ans2 == 1)
            {
                ans1 = v[0];
                ans2 = v[1];
            }
            else
            {
                if (ans1 != v[0] || ans2 != v[1])
                    ans1 = ans2 = 0;
            }
        }
    }

    if (ans1 == 0 && ans2 == 0)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < sz(vv); ++i)
    {
        if (vv[i].se.fi <= ans1 && ans2 <= vv[i].se.se)
            c[vv[i].fi] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            cout << "-1\n";
            return;
        }
    }

    cout << ans1 << ' ' << ans2 << "\n";
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