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
const int N = 503;

int n;
int a[N];

int p[N];

bool c[N][N][N];
int dp[N][N][N];
int rec(int i, int j, int z)
{
    if (i == n + 1)
        return 0;
    if (c[i][j][z])
        return dp[i][j][z];
    c[i][j][z] = true;
    if (j != i + 1)
        dp[i][j][z] = max(dp[i][j][z], a[j] + rec(i + 1, i + 1, z + 1));
    else
        dp[i][j][z] = max(dp[i][j][z], a[j] + rec(i + 1, 0, z + 1));
    dp[i][j][z] = max(dp[i][j][z], a[j] + rec(i + 1, j, z));
    if (z > 0 && i < j && j < n)
        dp[i][j][z] = max(dp[i][j][z], rec(i, j + 1, z - 1));
    if (z > 0)
        dp[i][j][z] = max(dp[i][j][z], rec(i, i + 1, z - 1));
    /*for (int k = i + 1; k <= n && (k - i) <= z; ++k)
    {
        if (a[k] > a[j])
            dp[i][j][z] = max(dp[i][j][z], rec(i, k, z - (k - i)));
    }*/
    return dp[i][j][z];
}

int ans;
void rec0(int i, int yans)
{
    if (i == n + 1)
    {
        ans = max(ans, yans);
        return;
    }

    rec0(i + 1, yans + a[i]);
    for (int j = 1; j < n; ++j)
    {
        swap(a[j], a[j + 1]);
        rec0(i + 1, yans + a[i]);
        swap(a[j], a[j + 1]);
    }
}

void solv()
{
    /*n = 7;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 1000000;*/

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            for (int z = 0; z <= n + 1; ++z)
            {
                dp[i][j][z] = 0;
                c[i][j][z] = false;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    cout << rec(1, 1, 1) << "\n";

    return;
    ans = 0;
    rec0(1, 0);
    if (ans != rec(1, 1, 1))
    {
        for (int i = 0; i <= n + 1; ++i)
        {
            for (int j = 0; j <= n + 1; ++j)
            {
                for (int z = 0; z <= n + 1; ++z)
                {
                    dp[i][j][z] = 0;
                    c[i][j][z] = false;
                }
            }
        }
        cout << n << "\n";
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << "\n";
        cout << "Wrong: " << rec(1, 1, 1) << "\n";
        cout << "Correct: " << ans << "\n";
        exit(0);
    }
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