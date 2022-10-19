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
const int N = 200005, M = 998244353;

int n, k;
vector<int> dp, p[N];

void solv()
{
    cin >> n >> k;

    int K = 0;
    int nn = n;
    int kk = k;
    while (nn > 0)
    {
        ++K;
        nn -= kk;
        ++kk;
    }
    K += 20;

    dp.assign(K, 0);
    dp[0] = 1;
    p[0] = dp;

    for (int i = 1; i < k; ++i)
        cout << "0 ";
    for (int i = k; i <= n; ++i)
    {
        dp.assign(K, 0);
        for (int j = 1; j < K; ++j)
        {
            if (i - (k + j - 1) >= 0 && !p[i - (k + j - 1)].empty())
                dp[j] = p[i - (k + j - 1)][j - 1];
        }

        p[i].assign(K, 0);
        for (int j = 0; j < K; ++j)
        {
            if ((i - (k + j)) >= 0 && !p[(i - (k + j))].empty())
                p[i][j] = p[i - (k + j)][j];
            p[i][j] = (p[i][j] + dp[j]) % M;
        }

        int ans = 0;
        for (int j = 0; j < K; ++j)
            ans = (ans + dp[j]) % M;
        cout << ans << ' ';

        bool z = false;
        for (int j = 0; j < K; ++j)
        {
            if (p[i][j])
            {
                z = true;
                break;
            }
        }
        if (!z)
            vector<int>().swap(p[i]);

        if (i - (k + K) >= 0)
            vector<int>().swap(p[i - (k + K)]);
    }
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