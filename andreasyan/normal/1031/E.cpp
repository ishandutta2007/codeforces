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

bool c[(1 << 22)];
int d[(1 << 22)];
int p[(1 << 22)];
void solv0(int n)
{
    vector<int> v;
    for (int x = 0; x < n; ++x)
    {
        for (int y = x + 1; y < n; ++y)
        {
            for (int z = y + 1; z < n; ++z)
            {
                if (y - x == z - y)
                {
                    v.push_back(((1 << x) | (1 << y) | (1 << z)));
                }
            }
        }
    }


    for (int x = 0; x < (1 << n); ++x)
        c[x] = false;

    queue<int> q;
    c[0] = true;
    d[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < sz(v); ++i)
        {
            int h = (x ^ v[i]);
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                p[h] = v[i];
                q.push(h);
            }
        }
    }
    return;

    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
        }
    }

    int maxu = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
            continue;
        maxu = max(maxu, d[x]);
    }
    cout << maxu << "\n";

    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
            continue;
        if (maxu == d[x])
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
            cout << endl;
            while (x)
            {
                for (int i = 0; i < n; ++i)
                {
                    if ((p[x] & (1 << i)))
                        cout << '1';
                    else
                        cout << '0';
                }
                cout << endl;
                x ^= p[x];
            }
            return;
        }
    }
}

void solv6()
{
    int n = 6;
    vector<int> v;
    for (int x = 0; x < n; ++x)
    {
        for (int y = x + 1; y < n; ++y)
        {
            for (int z = y + 1; z < n; ++z)
            {
                if (y - x == z - y)
                {
                    v.push_back(((1 << x) | (1 << y) | (1 << z)));
                }
            }
            if (x - (y - x) < 0)
                v.push_back(((1 << x) | (1 << y)));
        }
        v.push_back((1 << x));
    }


    for (int x = 0; x < (1 << n); ++x)
        c[x] = false;

    queue<int> q;
    c[0] = true;
    d[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < sz(v); ++i)
        {
            int h = (x ^ v[i]);
            if (!c[h])
            {
                c[h] = true;
                d[h] = d[x] + 1;
                p[h] = v[i];
                q.push(h);
            }
        }
    }
    return;

    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
        }
    }

    int maxu = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
            continue;
        maxu = max(maxu, d[x]);
    }
    cout << maxu << "\n";

    for (int x = 0; x < (1 << n); ++x)
    {
        if (!c[x])
            continue;
        if (maxu == d[x])
        {
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
            cout << endl;
            while (x)
            {
                for (int i = 0; i < n; ++i)
                {
                    if ((p[x] & (1 << i)))
                        cout << '1';
                    else
                        cout << '0';
                }
                cout << endl;
                x ^= p[x];
            }
            return;
        }
    }
}

int n;
int a[N];

vector<tuple<int, int, int> > ans;
void ubd(int x, int y, int z)
{
    assert(x >= 1 && x <= n && y >= 1 && y <= n && z >= 1 && z <= n);
    assert(x < y && y < z && (y - x) == (z - y));
    ans.push_back(tie(x, y, z));
    a[x] ^= 1;
    a[y] ^= 1;
    a[z] ^= 1;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    solv6();

    while (n >= 14)
    {
        int x = 0;
        for (int i = n - 5; i <= n; ++i)
        {
            x += (a[i] * (1 << (i - (n - 5))));
        }
        while (x)
        {
            vector<int> v;
            for (int i = 0; i < 6; ++i)
            {
                if ((p[x] & (1 << i)))
                    v.push_back(n - 5 + i);
            }
            if (sz(v) == 3)
                ubd(v[0], v[1], v[2]);
            else if (sz(v) == 2)
                ubd(v[0] - (v[1] - v[0]), v[0], v[1]);
            else
                ubd(n - 6 - (v[0] - (n - 6)), n - 6, v[0]);
            x ^= p[x];
        }
        n -= 6;
    }

    solv0(n);
    int x = 0;
    for (int i = 1; i <= n; ++i)
        x += (a[i] * (1 << (i - 1)));
    if (!c[x])
    {
        cout << "NO\n";
        return;
    }
    while (x)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            if ((p[x] & (1 << i)))
                v.push_back(i + 1);
        }
        ubd(v[0], v[1], v[2]);
        x ^= p[x];
    }

    for (int i = 1; i <= n; ++i)
        assert(!a[i]);
    cout << "YES\n";
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << "\n";
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