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
const int N = 1003, M = 1000000007;

int dp[N][N];
int t[N];

void pre()
{
    dp[0][0] = 1;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % M;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * 1LL * j) % M;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
            t[i] = (t[i] + dp[i][j]) % M;
    }
}

int n, m;
char a[N][N];

void solv()
{

    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    map<ll, int> mp;
    for (int j = 0; j < m; ++j)
    {
        ll x = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i][j] == '1')
                x += (1LL << i);
        }
        mp[x]++;
    }

    int ans = 1;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        ans = (ans * 1LL * t[it->se]) % M;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}