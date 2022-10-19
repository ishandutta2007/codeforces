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
const int N = 40004, M = 1000000007;

bool stg(int x)
{
    int cx = x;
    int y = 0;
    while (x)
    {
        y = (y * 10 + x % 10);
        x /= 10;
    }
    return (cx == y);
}

int dp[N];

void pre()
{
    dp[0] = 1;
    for (int x = 1; x < N; ++x)
    {
        if (!stg(x))
            continue;
        for (int i = 0; i < N - x - 1; ++i)
        {
            dp[i + x] = (dp[i + x] + dp[i]) % M;
        }
    }
}

void solv()
{
    int n;
    cin >> n;
    while (n--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
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