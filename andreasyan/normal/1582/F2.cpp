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
const int N = 1000006, K = 8192;

int n;
int a[N];

int dp[K];

vector<int> v[K];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int x = 0; x < K; ++x)
    {
        dp[x] = K;
    }

    for (int h = 0; h < K; ++h)
        v[h].push_back(0);
    dp[0] = -1;

    for (int i = 1; i <= n; ++i)
    {
        while (!v[a[i]].empty())
        {
            int x = v[a[i]].back();
            v[a[i]].pop_back();

            if (a[i] < dp[(x ^ a[i])])
            {
                for (int h = a[i] + 1; h <= min(dp[(x ^ a[i])], K - 1); ++h)
                {
                    v[h].push_back((x ^ a[i]));
                }
                dp[(x ^ a[i])] = a[i];
            }
        }
        /*for (int x = 0; x < K; ++x)
        {
            if (dp[x] < a[i])
                dp[(x ^ a[i])] = min(dp[(x ^ a[i])], a[i]);
        }*/
    }

    vector<int> ans;
    for (int x = 0; x < K; ++x)
    {
        if (dp[x] != K)
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