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

int f[N];
int rf[N];
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
    return f[n] * 1LL * rf[k] % M * rf[n - k] % M;
}

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];

    if (s % n != 0)
    {
        cout << "0\n";
        return;
    }

    vector<int> v1, v2;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < s / n)
            v1.push_back(a[i]);
        if (a[i] > s / n)
            v2.push_back(a[i]);
    }

    sort(all(v1));
    sort(all(v2));

    if (sz(v1) + sz(v2) == 0)
    {
        cout << "1\n";
        return;
    }

    int ans = 0;

    if (sz(v1) == 1 || sz(v2) == 1)
        ans = f[sz(v1) + sz(v2)];
    else
        ans = (f[sz(v1)] * 1LL * f[sz(v2)]) % M * 2 % M;

    int q = 1;
    for (int i = 1; i < sz(v1); ++i)
    {
        if (v1[i] != v1[i - 1])
        {
            ans = (ans * 1LL * rf[q]) % M;
            q = 1;
        }
        else
            ++q;
    }
    ans = (ans * 1LL * rf[q]) % M;

    q = 1;
    for (int i = 1; i < sz(v2); ++i)
    {
        if (v2[i] != v2[i - 1])
        {
            ans = (ans * 1LL * rf[q]) % M;
            q = 1;
        }
        else
            ++q;
    }
    ans = (ans * 1LL * rf[q]) % M;


    q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == s / n)
        {
            ++q;
        }
    }
    ans = (ans * 1LL * C(n, q)) % M;
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
        solv();
    return 0;
}