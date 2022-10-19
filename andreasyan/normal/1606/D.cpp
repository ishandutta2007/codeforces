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
const int N = 1000006;

int n, m;

void make(int**& a)
{
    a = new int*[n + 5];
    for (int i = 0; i < n + 5; ++i)
    {
        a[i] = new int[m + 5];
        for (int j = 0; j < m + 5; ++j)
            a[i][j] = 0;
    }
}

int** a;

int **pmax, **pmin, **smax, **smin;

struct ban
{
    int l1, r1;
    int l2, r2;
    int i;
};

bool operator<(const ban& a, const ban& b)
{
    return a.r1 < b.r1;
}

char ans[N];

void solv()
{
    cin >> n >> m;

    make(a);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    make(pmax);
    make(pmin);
    make(smax);
    make(smin);
    for (int i = 1; i <= n; ++i)
    {
        pmax[i][1] = a[i][1];
        for (int j = 2; j <= m; ++j)
            pmax[i][j] = max(pmax[i][j - 1], a[i][j]);
        pmin[i][1] = a[i][1];
        for (int j = 2; j <= m; ++j)
            pmin[i][j] = min(pmin[i][j - 1], a[i][j]);

        smax[i][m] = a[i][m];
        for (int j = m - 1; j >= 1; --j)
            smax[i][j] = max(smax[i][j + 1], a[i][j]);
        smin[i][m] = a[i][m];
        for (int j = m - 1; j >= 1; --j)
            smin[i][j] = min(smin[i][j + 1], a[i][j]);
    }

    for (int k = 1; k < m; ++k)
    {
        vector<ban> v;
        for (int i = 1; i <= n; ++i)
        {
            ban t;
            t.i = i;
            t.l1 = pmin[i][k];
            t.r1 = pmax[i][k];
            t.l2 = smin[i][k + 1];
            t.r2 = smax[i][k + 1];
            v.push_back(t);
        }

        sort(all(v));

        vector<int> L2, R2;

        for (int i = 0; i < n; ++i)
        {
            if (L2.empty())
                L2.push_back(v[i].l2);
            else
                L2.push_back(min(L2.back(), v[i].l2));
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (R2.empty())
                R2.push_back(v[i].r2);
            else
                R2.push_back(max(R2.back(), v[i].r2));
        }
        reverse(all(R2));

        vector<int> L1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (L1.empty())
                L1.push_back(v[i].l1);
            else
                L1.push_back(min(L1.back(), v[i].l1));
        }
        reverse(all(L1));

        for (int i = 0; i < n - 1; ++i)
        {
            if (v[i].r1 < L1[i + 1])
            {
                if (R2[i + 1] < L2[i])
                {
                    cout << "YES\n";
                    for (int j = 0; j <= i; ++j)
                        ans[v[j].i - 1] = 'B';
                    for (int j = i + 1; j < n; ++j)
                        ans[v[j].i - 1] = 'R';
                    ans[n] = 0;
                    cout << ans << ' ' << k << "\n";
                    return;
                }
            }
        }
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
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}