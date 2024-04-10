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
const int N = 2000006, M = 998244353;

int n;
int q[N];

int dp[N];
int p[N];

int ans;
bool c[N];
int u[N];
vector<pair<int, int> > v;
void rec(int i)
{
    if (i == 2 * n + 1)
    {
        bool z = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (v[i].se - v[i].fi == v[j].se - v[j].fi)
                    continue;
                if (v[i].fi < v[j].fi && v[j].se < v[i].se)
                    continue;
                if (v[j].fi < v[i].fi && v[i].se < v[j].se)
                    continue;
                z = false;
                break;
            }
            if (!z)
                break;
        }
        if (z)
        {
            for (int i = 1; i <= 2 * n; ++i)
                cout << u[i] << ' ';
            cout << "\n";
            ++ans;
        }
        return;
    }
    if (c[i])
    {
        rec(i + 1);
        return;
    }
    for (int j = i + 1; j <= 2 * n; ++j)
    {
        if (c[j])
            continue;
        c[i] = true;
        c[j] = true;
        u[i] = u[j] = i;
        v.push_back(m_p(i, j));
        rec(i + 1);
        v.pop_back();
        c[j] = false;
        c[i] = false;
    }
}

void solv()
{
    cin >> n;

    for (int i = 1; i < N; ++i)
    {
        for (int j = i + i; j < N; j += i)
            q[j]++;
    }

    dp[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        /*for (int q = 1; q <= i; ++q)
        {
            dp[i] = (dp[i] + dp[i - q]) % M;
        }*/
        dp[i] = p[i - 1];
        /*for (int j = 1; j < i; ++j)
        {
            if (i % j == 0)
                dp[i] = (dp[i] + 1) % M;
        }*/
        dp[i] = (dp[i] + q[i]) % M;
        p[i] = (p[i - 1] + dp[i]) % M;
    }


    cout << dp[n] << "\n";
    return;

    rec(1);
    cout << ans << "\n";
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