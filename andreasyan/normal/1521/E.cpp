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
const int N = 100005, M = 1003;

int m, k;
int a[N];
vector<pair<int, int> > v;

int b[M][M];
bool stg(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            b[i][j] = 0;
        }
    }

    vector<pair<int, int> > u;
    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 1; j <= n; j += 2)
        {
            u.push_back(m_p(i, j));
        }
    }

    bool z = false;
    for (int ii = 0; ii < k; ++ii)
    {
        int q = v[ii].fi;
        int x = v[ii].se;
        while (q > 0 && !u.empty())
        {
            --q;
            b[u.back().fi][u.back().se] = x;
            u.pop_back();
        }

        if (q)
        {
            if (z)
                return false;
            z = true;

            vector<pair<int, int> > uu;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (b[i][j])
                        continue;
                    if (i % 2 == 0 && j % 2 == 0)
                        continue;
                    if (b[i - 1][j - 1] != x && b[i + 1][j + 1] != x &&
                        b[i - 1][j + 1] != x && b[i + 1][j - 1] != x)
                    {
                        u.push_back(m_p(i, j));
                    }
                    else
                    {
                        uu.push_back(m_p(i, j));
                    }
                }
            }

            while (q > 0 && !u.empty())
            {
                --q;
                b[u.back().fi][u.back().se] = x;
                u.pop_back();
            }

            if (q)
                return false;

            while (!uu.empty())
            {
                u.push_back(uu.back());
                uu.pop_back();
            }
        }
    }
    return true;
}

void solv()
{
    cin >> m >> k;
    for (int i = 1; i <= k; ++i)
        cin >> a[i];

    v.clear();
    for (int i = 1; i <= k; ++i)
        v.push_back(m_p(a[i], i));
    sort(all(v));
    reverse(all(v));

    int l = 1, r = min(1000, m);
    int n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            n = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    assert(stg(n));
    cout << n << "\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << b[i][j] << ' ';
        }
        cout << "\n";
    }
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