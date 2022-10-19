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
int u[N];
int s[N];

vector<int> v[N];
vector<ll> p[N];

ll ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        p[i].clear();
        ans[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> u[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    for (int i = 1; i <= n; ++i)
    {
        v[u[i]].push_back(s[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(all(v[i]));
        p[i].push_back(0);
        for (int j = 0; j < v[i].size(); ++j)
        {
            p[i].push_back(p[i].back() + v[i][j]);
        }

        for (int k = 1; k <= v[i].size(); ++k)
        {
            ans[k] += p[i].back();
            ans[k] -= p[i][(sz(v[i]) % k)];
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
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