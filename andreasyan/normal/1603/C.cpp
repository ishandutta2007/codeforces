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
const int N = 100005, M = 998244353;

int n;
int a[N];

int dp[N];

vector<int> v;
void rec(int l, int r, int x)
{
    if (x / l == x / r)
    {
        v.push_back(x / l);
        return;
    }
    int m = (l + r) / 2;
    rec(l, m, x);
    rec(m + 1, r, x);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        v.clear();
        v.push_back(a[i]);
        if (i != n)
            rec(1, a[i + 1], a[i + 1]);

        vector<int> t;
        for (int j = 0; j < sz(v); ++j)
        {
            int u = v[j];

            int q = (a[i] / u);
            if (a[i] % u != 0)
                ++q;
            if (i == 1)
                dp[(a[i] / q)] = 0;
            t.push_back((dp[(a[i] / q)] + i * 1LL * (q - 1)) % M);
        }

        for (int j = 0; j < sz(v); ++j)
            dp[v[j]] = t[j];

        ans = (ans + dp[a[i]]) % M;
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

    int tt = 1;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}