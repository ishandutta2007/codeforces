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
const int N = 200005;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

ll lcm(int x, int y)
{
    return x * 1LL * y / gcd(x, y);
}

int n;
int a[N];

ll qry(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    ll ans;
    cin >> ans;
    //ans = lcm(a[x], a[y]);
    return ans;
}

ll maxp(ll x)
{
    ll maxu = 1;
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            maxu = max(maxu, i);
        }
    }
    if (x > 1)
        maxu = max(maxu, x);
    return maxu;
}

ll t[102][102];

bool c[N];
int g[N];

int ans[N];

void solv()
{
    cin >> n;
    //for (int i = 1; i <= n; ++i)
    //    cin >> a[i];

    if (n <= 100)
    {
        c[0] = c[1] = true;
        for (int i = 2; i < N; ++i)
        {
            if (c[i])
                continue;
            if (i * 1LL * i >= N)
                continue;
            for (int j = i * i; j < N; j += i)
                c[j] = true;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                t[i][j] = t[j][i] = qry(i, j);
            }
        }

        if (n == 3)
        {
            for (int i = 3; i < N; ++i)
            {
                vector<int> v;
                v.push_back(i - 2);
                v.push_back(i - 1);
                v.push_back(i);
                do
                {
                    bool z = true;
                    for (int i = 1; i <= n; ++i)
                    {
                        for (int j = i + 1; j <= n; ++j)
                        {
                            if (lcm(v[i - 1], v[j - 1]) != t[i][j])
                            {
                                z = false;
                                break;
                            }
                        }
                        if (!z)
                            break;
                    }
                    if (z)
                    {
                        cout << "! ";
                        for (int i = 0; i < n; ++i)
                            cout << v[i] << ' ';
                        cout << endl;
                        return;
                    }
                } while (next_permutation(all(v)));
            }
        }

        for (int i = 0; i < N; ++i)
        {
            if (c[i])
                continue;
            g[i] = 0;
            for (int x = 1; x <= n; ++x)
            {
                for (int y = x + 1; y <= n; ++y)
                {
                    if (x == y)
                        continue;
                    if (t[x][y] % i != 0)
                    {
                        g[i] = x;
                        break;
                    }
                }
                if (g[i])
                    break;
            }
        }

        for (int i = 1; i <= n; ++i)
            ans[i] = 1;

        for (int i = 0; i < N; ++i)
        {
            if (c[i])
                continue;
            if (!g[i])
                continue;
            for (int x = 1; x <= n; ++x)
            {
                if (x == g[i])
                    continue;
                ll s = t[x][g[i]];
                while (s % i == 0)
                {
                    s /= i;
                    ans[x] *= i;
                }
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << endl;
        return;
    }

    set<int> s;
    for (int i = 0; i < 5000; ++i)
    {
        s.insert(rnd() % n + 1);
    }
    if (sz(s) % 2 != 0)
    {
        s.erase(s.begin());
    }

    vector<int> v;
    for (auto it = s.begin(); it != s.end(); ++it)
        v.push_back(*it);

    int maxu = 1;
    int ii;
    for (int i = 0; i < sz(v) / 2; ++i)
    {
        ll x = qry(v[i], v[sz(v) - i - 1]);
        if (maxp(x) > maxu)
        {
            maxu = maxp(x);
            ii = i;
        }
    }

    int u = 1;
    if (u == v[ii])
        ++u;
    if (u == v[sz(v) - ii - 1])
        ++u;
    if (maxp(qry(v[ii], u)) == maxu)
    {
        u = v[ii];
    }
    else
    {
        u = v[sz(v) - ii - 1];
    }

    ans[u] = maxu;
    for (int i = 1; i <= n; ++i)
    {
        if (i == u)
            continue;
        ans[i] = qry(i, u) / maxu;
    }

    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
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