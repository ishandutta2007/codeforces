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
int c[N], x[N], y[N];

vector<int> v[N];

bool stg1(int k)
{
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        v[x[i]].push_back(i);
    }

    int g[3] = {1, 2, 3};
    do
    {
        vector<int> p, s;
        p.assign(n + 2, 0);
        s.assign(n + 2, 0);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = p[i - 1];
            for (int j = 0; j < sz(v[i]); ++j)
            {
                if (c[v[i][j]] == g[1])
                    ++p[i];
            }
        }
        for (int i = n; i >= 1; --i)
        {
            s[i] = s[i + 1];
            for (int j = 0; j < sz(v[i]); ++j)
            {
                if (c[v[i][j]] == g[2])
                    ++s[i];
            }
        }

        vector<int> vv;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < sz(v[i]); ++j)
            {
                if (c[v[i][j]] == g[0])
                    vv.push_back(i);
            }
            if (sz(vv) >= k)
            {
                if (s[vv.back() + 1] >= k && p[vv[sz(vv) - k] - 1] >= k)
                    return true;
            }
        }
    } while (next_permutation(g, g + 3));

    return false;
}

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

bool stg2(int k)
{
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        v[x[i]].push_back(i);
    }

    int g[3] = {1, 2, 3};
    do
    {
        for (int i = 1; i <= n; ++i)
            t[i] = 0;

        vector<int> s;
        s.assign(n + 2, 0);
        for (int i = n; i >= 1; --i)
        {
            s[i] = s[i + 1];
            for (int j = 0; j < sz(v[i]); ++j)
            {
                if (c[v[i][j]] == g[0])
                    ++s[i];
            }
        }

        priority_queue<int> q;
        int q2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            while (sz(q) > k)
                q.pop();
            if (s[i] >= k)
            {
                if (sz(q) == k)
                {
                    if (q2 - qry(q.top()) >= k)
                        return true;
                }
            }
            else
                break;
            for (int j = 0; j < sz(v[i]); ++j)
            {
                if (c[v[i][j]] == g[1])
                {
                    q.push(y[v[i][j]]);
                }
                else if (c[v[i][j]] == g[2])
                {
                    ++q2;
                    ubd(y[v[i][j]]);
                }
            }
        }
    } while (next_permutation(g, g + 3));

    return false;
}

bool stg(int k)
{
    if (stg1(k))
        return true;
    for (int i = 1; i <= n; ++i)
        swap(x[i], y[i]);
    if (stg1(k))
        return true;
    for (int i = 1; i <= n; ++i)
        swap(x[i], y[i]);

    if (stg2(k))
        return true;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = n - x[i] + 1;
        y[i] = n - y[i] + 1;
    }
    if (stg2(k))
        return true;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = n - x[i] + 1;
        y[i] = n - y[i] + 1;
    }

    for (int i = 1; i <= n; ++i)
        swap(x[i], y[i]);
    if (stg2(k))
        return true;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = n - x[i] + 1;
        y[i] = n - y[i] + 1;
    }
    if (stg2(k))
        return true;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = n - x[i] + 1;
        y[i] = n - y[i] + 1;
    }
    for (int i = 1; i <= n; ++i)
        swap(x[i], y[i]);
    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> c[i];

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(x[i]);
    sort(all(v));
    for (int i = 1; i <= n; ++i)
        x[i] = lower_bound(all(v), x[i]) - v.begin() + 1;

    v.clear();
    for (int i = 1; i <= n; ++i)
        v.push_back(y[i]);
    sort(all(v));
    for (int i = 1; i <= n; ++i)
        y[i] = lower_bound(all(v), y[i]) - v.begin() + 1;

    int l = 1, r = n / 3;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    cout << ans * 3 << "\n";
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