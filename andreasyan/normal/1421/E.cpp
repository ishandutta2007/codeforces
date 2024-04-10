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
const int N = 15, M = 200005;
const ll INF = 1000000009000000009;

int c[N][N];
set<vector<int> > s[N];

void por()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }

    s[1].insert({0});
    for (int n = 2; n < N; ++n)
    {
        for (int m = 1; m < n; ++m)
        {
            for (auto it = s[m].begin(); it != s[m].end(); ++it)
            {
                for (auto jt = s[n - m].begin(); jt != s[n - m].end(); ++jt)
                {
                    vector<int> v = *it;
                    for (int i = 0; i < n - m; ++i)
                        v.push_back((*jt)[i]);
                    for (int i = 0; i < n; ++i)
                        v[i] ^= 1;
                    s[n].insert(v);
                }
            }
        }

        vector<pair<int, vector<int> > > vv;
        vector<int> qq;
        qq.assign(n + 1, 0);
        for (auto it = s[n].begin(); it != s[n].end(); ++it)
        {
            int q = 0;
            for (int i = 0; i < n; ++i)
            {
                q += (*it)[i];
            }
            qq[q]++;
            vv.push_back(m_p(q, (*it)));
        }

        sort(all(vv));
        cout << n << endl;
        /*for (int i = 0; i < sz(vv); ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << vv[i].se[j];
            cout << endl;
        }*/

        for (int q = 0; q <= n; ++q)
        {
            if (qq[q] == 0)
                continue;
            cout << q << ' ';
        }
        for (int q = 0; q <= n; ++q)
        {
            if (qq[q] == 0)
                continue;
            if (c[n][q] != qq[q])
            {
                for (int x = 0; x < (1 << n); ++x)
                {
                    int u = 0;
                    vector<int> v;
                    for (int i = 0; i < n; ++i)
                    {
                        if ((x & (1 << i)))
                        {
                            ++u;
                            v.push_back(1);
                        }
                        else
                            v.push_back(0);
                    }
                    if (u == q)
                    {
                        if (s[n].find(v) == s[n].end())
                        {
                            for (int i = 0; i < n; ++i)
                                cout << v[i];
                            cout << endl;
                        }
                    }
                }
            }
        }
        cout << endl << endl;
    }
}

int n;
pair<int, int> a[M];
ll p[M];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i].se = i;
        cin >> a[i].fi;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i].fi;

    if (n == 1)
    {
        cout << p[1] << "\n";
        return;
    }

    ll ans = -INF;

    if (n % 2 == 0)
    {
        int m = ((n / 2) % 3 + 1) % 3;
        for (int i = 0; i <= n; ++i)
        {
            if (i % 3 == m)
            {
                ans = max(ans, p[n] - p[i] - p[i]);
            }
        }
    }
    else
    {
        int m = (n / 2) % 3;

        assert((n / 2) % 3 == m);
        vector<int> v;
        for (int i = 1; i <= n / 2; ++i)
            v.push_back(a[i].se);
        sort(all(v));

        bool z = true;
        for (int i = 0, j = 2; i < sz(v); ++i, j += 2)
        {
            if (v[i] != j)
            {
                z = false;
                break;
            }
        }

        for (int i = 0; i <= n; ++i)
        {
            if (i % 3 == m)
            {
                if (i == n / 2 && z)
                    continue;
                ans = max(ans, p[n] - p[i] - p[i]);
            }
        }

        if (z)
        {
            ll yans = 0;
            for (int i = 1; i <= n / 2 - 1; ++i)
                yans -= a[i].fi;
            yans += a[n / 2].fi;
            yans -= a[n / 2 + 1].fi;
            for (int i = n / 2 + 2; i <= n; ++i)
                yans += a[i].fi;
            ans = max(ans, yans);
        }
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

    //por();
    //return 0;

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}