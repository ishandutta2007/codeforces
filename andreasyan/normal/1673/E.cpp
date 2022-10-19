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
const int N = (1 << 21);

int n, k;
ll b[N];

int f[N];
void pre()
{
    f[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        f[i] = f[i - 1];
        int x = i;
        while (x % 2 == 0)
        {
            ++f[i];
            x /= 2;
        }
    }
}

int C(int n, int k)
{
    int q = f[n] - f[k] - f[n - k];
    if (q > 0)
        return 0;
    return 1;
}

map<pair<int, int>, int> mp;
int F(int n, int k)
{
    k = max(k, 0);
    if (mp.find(m_p(n, k)) != mp.end())
        return mp[m_p(n, k)];

    int ck = k;
    int ans = 0;
    while (k <= n)
    {
        ans ^= C(n, k);
        ++k;
    }
    return mp[m_p(n, ck)] = ans;
}

int ans[N];
void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        int u = 0;
        for (int j = i; j <= n; ++j)
        {
            if (u > 20)
                break;
            if ((b[i] << u) >= (1 << 20))
                break;

            int nn = n - 1 - (j - i);
            int kk = k;
            if (i > 1)
            {
                --nn;
                --kk;
            }
            if (j < n)
            {
                --nn;
                --kk;
            }

            ans[(b[i] << u)] ^= F(nn, kk);

            u += b[j + 1];
        }
    }

    bool z = false;
    for (int i = N - 1; i >= 0; --i)
    {
        if (ans[i])
        {
            z = true;
        }
        if (z)
            cout << ans[i];
    }
    if (!z)
        cout << "0";
    cout << "\n";
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