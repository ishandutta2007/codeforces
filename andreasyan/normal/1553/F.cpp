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
const int N = 300005, S = 560, NN = 610005;

int n;
int a[NN];

int q[NN];
vector<int> v;
ll p[NN];

ll u[NN];
ll uu[NN];

void ubd(int l, int r, ll x, ll y)
{
    if (l > r)
        return;
    u[l] += x;
    uu[l] += y;
    uu[r] -= y;
    u[r + 1] -= (x + (r - l) * y);
}

void rubd(int l, int r, ll x, ll y)
{
    ll v = x + (r - l) * y;
    ubd(l, r, v, -y);
}

void clr()
{
    for (int i = 0; i < N; ++i)
        u[i] = uu[i] = 0;

    for (int i = 0; i < sz(v); ++i)
    {
        ubd(v[i] + 1, v[i] * 2 - 1, v[i] + 1, 1);
        for (int j = v[i] * 2; j < N; j += v[i])
        {
            ubd(j, j + v[i] - 1, v[i], 1);
        }

        ubd(1, v[i] - 1, 1, 1);

        for (int j = 1; j <= S; ++j)
        {
            if (v[i] / j <= S)
            {
                for (int k = 1; k <= v[i] / j; ++k)
                {
                    ubd(k, k, (v[i] % k), 0);
                }
                break;
            }
            rubd(v[i] / (j + 1) + 1, v[i] / j, v[i] % j, j);
        }
    }

    ll s = 0;
    ll a = 0;
    for (int i = 0; i < N; ++i)
    {
        s += u[i];
        s += a;
        a += uu[i];

        p[i] += s;
    }

    v.clear();
}

ll ans[N];

void solv()
{
    cin >> n;

    /*v.push_back(n);
    clr();
    for (int i = 1; i < N; ++i)
    {
        if ((n % i + i % n) != p[i])
        {
            cout << "WA\n";
            cout << i << "\n";
            cout << (n % i + i % n) << " " << p[i] << "\n";
            return;
        }
    }
    cout << "OK\n";
    return;*/

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    /*n = 1000;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 300000 + 1;*/

    ll s = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= S; ++j)
        {
            s += q[j] * 1LL * (a[i] % j + j % a[i]);
        }
        for (int j = 0; j < sz(v); ++j)
        {
            s += (a[i] % v[j] + v[j] % a[i]);
        }
        s += p[a[i]];

        ans[i] = s;

        if (a[i] <= S)
        {
            q[a[i]]++;
        }
        else
        {
            v.push_back(a[i]);
        }

        if (i % S == 0)
        {
            clr();
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";

    return;

    s = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            s += (a[i] % a[j] + a[j] % a[i]);
        }
        cout << s << ' ';
        assert(ans[i] == s);
    }
    cout << "\n";
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