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
const int N = 100005;

int n, m, k;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

int qq;
int q[N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        kpc(x, y);
    }

    for (int i = 1; i <= n; ++i)
        q[fi(i)]++;

    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (q[i])
        {
            ++qq;
            ans = (ans * 1LL * q[i]) % k;
        }
    }

    if (qq == 1)
    {
        cout << (1 % k) << "\n";
        return;
    }

    for (int i = 0; i < qq - 2; ++i)
        ans = (ans * 1LL * n) % k;

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
    {
        solv();
    }
    return 0;
}