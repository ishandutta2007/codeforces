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

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

void por()
{
    int b = 5;
    int ans = 0;
    for (int x = 0; x < (1 << b); ++x)
    {
        for (int y = 0; y < (1 << b); ++y)
        {
            for (int z = 0; z < (1 << b); ++z)
            {
                vector<int> v;
                v.push_back((x ^ y));
                v.push_back((x ^ z));
                v.push_back((y ^ z));
                sort(all(v));
                if (v[1] + v[2] > v[0])
                {
                    //assert(x != y && y != z);
                    //assert(v[0] != v[1] && v[1] != v[2]);
                    ++ans;
                    continue;
                    for (int i = b - 1; i >= 0; --i)
                    {
                        if ((x & (1 << i)))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    cout << endl;
                    for (int i = b - 1; i >= 0; --i)
                    {
                        if ((y & (1 << i)))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    cout << endl;
                    for (int i = b - 1; i >= 0; --i)
                    {
                        if ((z & (1 << i)))
                            cout << '1';
                        else
                            cout << '0';
                    }
                    cout << endl;
                    cout << endl;
                }
            }
        }
    }
    cout << ans << "\n";
}

int n;
char a[N];

void ph(int& x, ll y)
{
    x = (x + y) % M;
}

int dp[N][7][2];
void solv()
{
    cin >> a;
    n = strlen(a);

    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++i)
    {
        // 0
        // 0 0
        ph(dp[i + 1][0][0], dp[i][0][0] * 2);
        ph(dp[i + 1][1][0], dp[i][0][0]);
        ph(dp[i + 1][2][0], dp[i][0][0]);

        // 1 0
        ph(dp[i + 1][1][0], dp[i][1][0] * 4LL);
        ph(dp[i + 1][4][0], dp[i][1][0]);
        ph(dp[i + 1][3][0], dp[i][1][0]);

        // 2 0
        ph(dp[i + 1][2][0], dp[i][2][0] * 4LL);
        ph(dp[i + 1][5][0], dp[i][2][0]);
        ph(dp[i + 1][4][0], dp[i][2][0]);

        // 3 0
        ph(dp[i + 1][3][0], dp[i][3][0] * 6LL);
        ph(dp[i + 1][6][0], dp[i][3][0] * 2);

        // 4 0
        ph(dp[i + 1][4][0], dp[i][4][0] * 6LL);
        ph(dp[i + 1][6][0], dp[i][4][0] * 2);

        // 5 0
        ph(dp[i + 1][5][0], dp[i][5][0] * 6LL);
        ph(dp[i + 1][6][0], dp[i][5][0] * 2);

        // 6 0
        ph(dp[i + 1][6][0], dp[i][6][0] * 8LL);

        // 1
        if (a[i] == '0')
        {
            // 0 1
            ph(dp[i + 1][0][1], dp[i][0][1]);

            // 1 1
            ph(dp[i + 1][1][1], dp[i][1][1] * 2);

            // 2 1
            ph(dp[i + 1][2][1], dp[i][2][1] * 2);
            ph(dp[i + 1][5][1], dp[i][2][1]);

            // 345 1
            for (int t = 3; t <= 5; ++t)
            {
                for (int x = 0; x < 2; ++x)
                {
                    for (int y = 0; y < 2; ++y)
                    {
                        for (int z = 0; z < 2; ++z)
                        {
                            if (x == 1)
                                continue;
                            if ((t == 3 && x != y && x != z) || (t == 4 && y != x && y != z) || (t == 5 && z != x && z != y))
                                ph(dp[i + 1][6][1], dp[i][t][1]);
                            else
                                ph(dp[i + 1][t][1], dp[i][t][1]);
                        }
                    }
                }
            }

            // 6 1
            ph(dp[i + 1][6][1], dp[i][6][1] * 4LL);
        }
        else
        {
            // 0 1
            ph(dp[i + 1][0][0], dp[i][0][1]);
            ph(dp[i + 1][0][1], dp[i][0][1]);
            ph(dp[i + 1][1][1], dp[i][0][1]);
            ph(dp[i + 1][2][1], dp[i][0][1]);

            // 1 1
            ph(dp[i + 1][1][0], dp[i][1][1] * 2);
            ph(dp[i + 1][1][1], dp[i][1][1] * 2);
            ph(dp[i + 1][4][1], dp[i][1][1]);
            ph(dp[i + 1][3][1], dp[i][1][1]);

            // 2 1
            ph(dp[i + 1][2][0], dp[i][2][1] * 2);
            ph(dp[i + 1][2][1], dp[i][2][1] * 2);
            ph(dp[i + 1][5][0], dp[i][2][1]);
            ph(dp[i + 1][4][1], dp[i][2][1]);

            // 345 1
            for (int t = 3; t <= 5; ++t)
            {
                for (int x = 0; x < 2; ++x)
                {
                    for (int y = 0; y < 2; ++y)
                    {
                        for (int z = 0; z < 2; ++z)
                        {
                            if ((t == 3 && x != y && x != z) || (t == 4 && y != x && y != z) || (t == 5 && z != x && z != y))
                                ph(dp[i + 1][6][x], dp[i][t][1]);
                            else
                                ph(dp[i + 1][t][x], dp[i][t][1]);
                        }
                    }
                }
            }

            // 6 1
            ph(dp[i + 1][6][0], dp[i][6][1] * 4LL);
            ph(dp[i + 1][6][1], dp[i][6][1] * 4LL);
        }
    }

    cout << ((dp[n][6][0] + dp[n][6][1]) * 6LL) % M << "\n";
}


int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    //por();
    //return 0;

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}