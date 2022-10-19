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

int n, m;
vector<int> r[N], c[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;
            r[x].push_back(i);
            c[x].push_back(j);
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i)
    {
        sort(all(r[i]));
        sort(all(c[i]));

        ll s = 0;
        for (int j = 0; j < sz(r[i]); ++j)
        {
            ans += r[i][j] * 1LL * j;
            ans -= s;
            s += r[i][j];
        }

        s = 0;
        for (int j = 0; j < sz(c[i]); ++j)
        {
            ans += c[i][j] * 1LL * j;
            ans -= s;
            s += c[i][j];
        }
    }

    cout << ans << "\n";
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