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
const int N = 100005, K = 512;

int n;
int a[N];

int dp[K];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int x = 0; x < K; ++x)
    {
        dp[x] = N;
    }

    dp[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        for (int x = 0; x < K; ++x)
        {
            if (dp[x] < a[i])
                dp[(x ^ a[i])] = min(dp[(x ^ a[i])], a[i]);
        }
    }

    vector<int> ans;
    for (int x = 0; x < K; ++x)
    {
        if (dp[x] != N)
            ans.push_back(x);
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}