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
const int N = 5013;
const ll INF = 1000000009000000009;

int p[2];
ll t[2];
int h0, s;

vector<pair<ll, int> > v;
ll dp[N][N];

void solv()
{
    cin >> p[0] >> t[0];
    cin >> p[1] >> t[1];
    cin >> h0 >> s;

    for (int z = 0; z < 2; ++z)
    {
        for (int i = 1; i <= h0 + 2; ++i)
            v.push_back(m_p(i * t[z], z));
    }
    sort(all(v));
    while (sz(v) > h0 + 2)
        v.pop_back();

    for (int h = 1; h <= h0; ++h)
    {
        for (int i = 0; i < sz(v) - 2; ++i)
        {
            if (h - (p[v[i].se] - s) <= 0)
                dp[h][i] = 0;
            else
            {
                dp[h][i] = (v[i + 1].fi - v[i].fi) + dp[h - (p[v[i].se] - s)][i + 1];
            }
            if (v[i + 1].se != v[i].se)
            {
                if (h - (p[0] + p[1] - s) <= 0)
                    dp[h][i] = min(dp[h][i], v[i + 1].fi - v[i].fi);
                else
                    dp[h][i] = min(dp[h][i], (v[i + 1].fi - v[i].fi) + dp[h - (p[0] + p[1] - s)][sz(v)]);
            }
        }
        dp[h][sz(v)] = v[0].fi + dp[h][0];
    }

    cout << dp[h0][sz(v)] << "\n";
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