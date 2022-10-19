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
const int N = 100005, M = 1000000007;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

vector<int> v[N];
int q[N];

int n;
int t[N];

void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i)
            continue;
        for (int c = 1; c < i; ++c)
        {
            for (int j = 0; j < sz(v[i - c]); ++j)
            {
                int d = v[i - c][j];
                if (gcd(c, d) > 1)
                    continue;
                t[i] = (t[i] + d * 1LL * c * 1LL * q[(i - c) / d]) % M;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < sz(v[n]); ++i)
    {
        int g = v[n][i];
        ans = (ans + t[n / g] * 1LL * g) % M;
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

    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            v[j].push_back(i);
    }
    for (int i = 2; i < N; ++i)
    {
        q[i] = (i - 1);
        for (int j = 1; j < sz(v[i]); ++j)
        {
            q[i] -= q[i / v[i][j]];
        }
    }

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}