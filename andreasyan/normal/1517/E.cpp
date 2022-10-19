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

int n;

void por()
{
    cin >> n;

    set<int> s1;
    for (int x = 0; x < (1 << n); ++x)
    {
        vector<int> c;
        vector<int> p;
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                c.push_back(i);
            else
                p.push_back(i);
        }

        bool z = true;
        for (int i = 1; i < sz(c) - 1; ++i)
        {
            if (!(2 * c[i] <= c[i - 1] + c[i + 1]))
                z = false;
        }
        for (int i = 1; i < sz(p) - 1; ++i)
        {
            if (!(2 * p[i] >= p[i - 1] + p[i + 1]))
                z = false;
        }

        if (z)
        {
            s1.insert(x);
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << '1';
                else
                    cout << '0';
            }
            cout << "\n";
        }
    }

    set<int> s2;
    for (int x = 0; x < (1 << n); ++x)
    {
        vector<int> c;
        vector<int> p;
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                c.push_back(i);
            else
                p.push_back(i);
        }

        bool z = true;
        if ((!(x & (1 << (n - 1)))))
        {
            if (!c.empty())
            {
                if (c[0] > 2)
                {
                    z = false;
                }
                int j = 0;
                while (j + 1 < sz(c) && c[j + 1] == c[j] + 1)
                    ++j;

                for (int i = j + 1; i < sz(c); ++i)
                {
                    if (c[i] != c[i - 1] + 2)
                    {
                        z = false;
                    }
                }
            }
        }
        else
        {
            if (c.back() - c[0] != sz(c) - 1)
            {
                c.pop_back();
                assert(!c.empty());
                if (c.back() == n - 1)
                {
                    z = false;
                }
                if (c[0] > 2)
                {
                    z = false;
                }
                int j = 0;
                while (j + 1 < sz(c) && c[j + 1] == c[j] + 1)
                    ++j;

                for (int i = j + 1; i < sz(c); ++i)
                {
                    if (c[i] != c[i - 1] + 2)
                    {
                        z = false;
                    }
                }
            }
        }

        if (z)
        {
            s2.insert(x);
            continue;
            if (s1.find(x) == s1.end())
            {
                for (int i = 0; i < n; ++i)
                {
                    if ((x & (1 << i)))
                        cout << '1';
                    else
                        cout << '0';
                }
                cout << "\n";
                return;
            }
        }
    }

    assert(s1 == s2);
}

ll ans;

ll a[N];

ll S;
ll p[N];
ll p2[N];

void do1()
{
    deque<int> d[2];
    for (int i = 1; i < n; ++i)
        d[i % 2].push_back(i);

    for (int u = 1; u < n; ++u)
    {
        int i = u;
        int l = 0, r = sz(d[i % 2]) - 1;
        int yans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[u] + p2[d[i % 2][m]] - p2[u] < S)
            {
                yans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        d[i % 2].pop_front();

        ans += (yans + 1);
    }
}

void do2()
{
    deque<int> d[2];
    for (int i = 2; i < n; ++i)
        d[i % 2].push_back(i);

    for (int u = 2; u < n; ++u)
    {
        int i = u;
        int l = 0, r = sz(d[i % 2]) - 1;
        int yans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[u] + p2[d[i % 2][m]] - p2[u] - a[1] < S)
            {
                yans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        d[i % 2].pop_front();

        ans += (yans + 1);
    }
}

void do3()
{
    deque<int> d[2];
    for (int i = 1; i < n - 1; ++i)
        d[i % 2].push_back(i);

    for (int u = 1; u < n - 1; ++u)
    {
        int i = u;
        int l = 0, r = sz(d[i % 2]) - 1;
        int yans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[u] + p2[d[i % 2][m]] - p2[u] + a[n] < S)
            {
                yans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        d[i % 2].pop_front();

        ans += (yans + 1);
    }
}

void do4()
{
    deque<int> d[2];
    for (int i = 2; i < n - 1; ++i)
        d[i % 2].push_back(i);

    for (int u = 2; u < n - 1; ++u)
    {
        int i = u;
        int l = 0, r = sz(d[i % 2]) - 1;
        int yans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[u] + p2[d[i % 2][m]] - p2[u] - a[1] + a[n] < S)
            {
                yans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        d[i % 2].pop_front();

        ans += (yans + 1);
    }
}

void solv()
{
    ans = 0;
    S = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        S += a[i];
    for (int i = 1; i <= n; ++i)
        a[i] *= 2;

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        p2[i] = p2[i - 2] + a[i];

    ++ans;
    do1();
    do2();
    ll s = 0;
    for (int i = n; i >= 1; --i)
    {
        s += a[i];
        if (s < S)
            ++ans;
    }
    do3();
    do4();

    cout << ans % 998244353 << "\n";
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