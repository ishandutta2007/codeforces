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

int n;
int a[N], b[N];

void por()
{

    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = i;

    int ans = 0;
    do
    {
        int yans = 0;
        for (int i = 1; i < n; ++i)
            yans += abs(a[i] - a[i + 1]);
        yans += abs(a[1] - a[n]);

        if (yans > ans)
        {
            ans = yans;
            for (int i = 1; i <= n; ++i)
                b[i] = a[i];
        }
    } while (next_permutation(a + 1, a + n + 1));

    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << "\n";
}

int u[N];
bool c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        u[a[i]] = i;

    for (int i = 1; i <= n; ++i)
        c[i] = false;

    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;

        int z = 0;
        int x = i;
        while (!c[x])
        {
            c[x] = true;
            z ^= 1;
            x = u[b[x]];
        }
        q += z;
    }

    int l, r;
    if (n % 2 == 0)
    {
        q /= 2;
        l = n / 2 + 1 - q;
        r = n / 2 + q;
    }
    else
    {
        q /= 2;
        l = n / 2 + 1 - q;
        r = n / 2 + 1 + q;
    }

    ll ans = 0;
    for (int i = r + 1; i <= n; ++i)
        ans += i;
    for (int i = l - 1; i >= 1; --i)
        ans -= i;
    ans *= 2;

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
    {
        solv();
    }
    return 0;
}