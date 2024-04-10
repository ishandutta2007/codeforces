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

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    if (n < k)
        return 0;
    return (f[n] * 1LL * rf[k] % M * rf[n - k]) % M;
}

int n, l, r;

int c[N];

void solv()
{
    cin >> n >> l >> r;

    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(m_p(i - l + 1, -i));
        v.push_back(m_p(r - i + 1, i));
    }
    v.push_back(m_p(1, 0));
    sort(all(v));

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    int qpl = 0, qpr = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].se < 0)
        {
            int x = -v[i].se;
            if (c[x] == 0)
            {
                c[x] = -1;
                ++qpr;
            }
            else
                break;
        }
        else if (v[i].se > 0)
        {
            int x = v[i].se;
            if (c[x] == 0)
            {
                c[x] = 1;
                ++qpl;
            }
            else
                break;
        }
        if (n % 2 == 0)
        {
            if (qpl <= n / 2 && qpr <= n / 2)
            {
                ans = (ans + C(n - qpl - qpr, n / 2 - qpl) * 1LL * (v[i + 1].fi - v[i].fi)) % M;
            }
        }
        else
        {
            if (qpl <= n / 2 && qpr <= n / 2 + 1)
            {
                ans = (ans + C(n - qpl - qpr, n / 2 - qpl) * 1LL * (v[i + 1].fi - v[i].fi)) % M;
            }
            if (qpl <= n / 2 + 1 && qpr <= n / 2)
            {
                ans = (ans + C(n - qpl - qpr, n / 2 - qpr) * 1LL * (v[i + 1].fi - v[i].fi)) % M;
            }
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}