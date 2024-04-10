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
const int N = 200005, M = 1000000007;

int dp[N];
int dpp[N];
void pre()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % M;
    }

    dpp[0] = dp[0];
    for (int i = 1; i < N; ++i)
        dpp[i] = (dpp[i - 1] + dp[i]) % M;
}

int n, m;
int a[N];

int z;
int t[N * 30][2];
bool c[N * 30];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    z = 0;
    t[z][0] = t[z][1] = c[z] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            continue;
        vector<int> v;
        int x = a[i];
        while (x)
        {
            v.push_back(x % 2);
            x /= 2;
        }
        reverse(all(v));

        int pos = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            if (!t[pos][v[i]])
            {
                t[pos][v[i]] = ++z;
                t[z][0] = t[z][1] = c[z] = 0;
            }
            pos = t[pos][v[i]];
        }
        c[pos] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            continue;
        vector<int> v;
        int x = a[i];
        while (x)
        {
            v.push_back(x % 2);
            x /= 2;
        }
        reverse(all(v));

        int pos = 0;
        bool z = false;
        for (int i = 0; i < sz(v); ++i)
        {
            pos = t[pos][v[i]];
            if (c[pos] && i < sz(v) - 1)
            {
                int q0 = 0;
                z = true;
                for (int j = i + 1; j < sz(v); ++j)
                {
                    if (!v[j])
                        ++q0;
                    else
                    {
                        if (q0 % 2 == 1)
                        {
                            z = false;
                            break;
                        }
                        q0 = 0;
                    }
                }
                if (q0 % 2 == 1)
                    z = false;
                q0 = 0;

                if (z)
                {
                    break;
                }
            }
        }

        if (!z)
        {
            if (sz(v) <= m)
                ans = (ans + dpp[m - sz(v)]) % M;
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

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}