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
const int N = 1003;

int n;
int a[N];

pair<int, int> u[N * N];

map<int, vector<int> > mp;

vector<int> v;
bool c[N];
bool rec(int i, int e)
{
    if (sz(v) > e)
        return false;
    if (i == n + 1)
    {
        if (sz(v) != e)
            return false;
        int s = 0;
        for (int i = 0; i < e; ++i)
            s += a[v[i]];
        if (mp.find(s) != mp.end())
        {
            vector<int> u = mp[s];

            cout << "YES\n";
            int t = 0;
            for (int i = 0; i < e; ++i)
            {
                t = a[v[i]] - t;
                cout << t << ' ';
                t = a[u[i]] - t;
                cout << t << ' ';
            }
            assert(t == 0);

            for (int i = 0; i < e; ++i)
                c[v[i]] = c[u[i]] = true;
            for (int i = 1; i <= n; ++i)
            {
                if (!c[i])
                    cout << a[i] << ' ';
            }
            cout << "\n";
            return true;
        }
        mp[s] = v;
        return false;
    }
    if (sz(v) + n - i >= e && rec(i + 1, e))
        return true;
    v.push_back(i);
    if (rec(i + 1, e))
        return true;
    v.pop_back();
    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            cout << "YES\n";
            cout << "0 ";
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                cout << a[j] << ' ';
            }
            cout << "\n";
            return;
        }
    }

    if (n == 2)
    {
        cout << "NO\n";
        return;
    }
    if (n == 3)
    {
        if ((a[1] + a[2] + a[3]) % 2 == 0)
        {
            int x = (a[1] + a[2] - a[3]) / 2;
            int z = a[2] - x;
            int y = a[3] - z;
            cout << "YES\n";
            cout << x << ' ' << y << ' ' << z << "\n";
            return;
        }
        cout << "NO\n";
        return;
    }

    vector<int> v[2];
    for (int i = 1; i <= n; ++i)
        v[a[i] % 2].push_back(a[i]);

    if (!v[0].empty())
    {
        int a1, a2, a3;
        if (sz(v[0]) >= 3)
        {
            a1 = v[0].back();
            v[0].pop_back();
            a2 = v[0].back();
            v[0].pop_back();
            a3 = v[0].back();
            v[0].pop_back();
        }
        else
        {
            a1 = v[0].back();
            v[0].pop_back();
            a2 = v[1].back();
            v[1].pop_back();
            a3 = v[1].back();
            v[1].pop_back();
        }
        int x = (a1 + a2 - a3) / 2;
        int z = a2 - x;
        int y = a3 - z;
        cout << "YES\n";
        cout << x << ' ' << y << ' ' << z << ' ';
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < sz(v[i]); ++j)
            {
                cout << v[i][j] - x << ' ';
            }
        }
        cout << "\n";
        return;
    }

    for (int e = 2; e <= n / 2; ++e)
    {
        mp.clear();
        if (rec(1, e))
            return;
    }
    cout << "NO\n";
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