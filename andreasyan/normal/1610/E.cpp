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

bool stg(vector<int> v)
{
    int s = 0;
    for (int i = 0; i < sz(v); ++i)
        s += v[i];

    int ans = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] * sz(v) > s)
            ++ans;
        else if (v[i] * sz(v) < s)
            --ans;
    }

    return (ans > 0);
}

bool stgg(vector<int> v)
{
    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        vector<int> vv;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
                vv.push_back(v[i]);
        }
        if (stg(vv))
            return false;
    }
    return true;
}

bool stgg1(vector<int> v)
{
    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        vector<int> vv;
        vector<int> vi;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                vi.push_back(i);
                vv.push_back(v[i]);
            }
        }
        if (sz(vv) != 3)
            continue;
        if (vi[0] != 0)
            continue;
        if (vi[1] != vi[2] - 1)
            continue;
        if (stg(vv))
            return false;
    }
    return true;
}

void por()
{
    int n = rnf() % 10 + 3;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(rnf() % 10 + 1);
    }

    sort(all(v));

    if (stgg(v) != stgg1(v))
    {
        for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';
        cout << "\n";
        exit(0);
    }
}

int n;
int a[N];

int u[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    u[n] = n;
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] == a[i + 1])
            u[i] = u[i + 1];
        else
            u[i] = i;
    }

    int ans = n;
    for (int i = 1; i <= n; ++i)
    {
        int yans = u[i] - i + 1;

        int j = u[i];
        while (1)
        {
            int l = j + 1;
            int r = n;
            int u = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (2 * a[j] - a[m] <= a[i])
                {
                    u = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (u == -1)
                break;
            j = u;
            ++yans;
        }

        ans = min(ans, n - yans);
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

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}