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
const int N = 10004;

int n, k;
int c[N];
vector<int> v[N];

int a[N], b[N];

struct ban
{
    int l, r, g;
    ban(){}
    ban(int l, int r, int g)
    {
        this->l = l;
        this->r = r;
        this->g = g;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int q[N];
bool solv()
{
    for (int i = 1; i <= n * k; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        a[i] = b[i] = 0;
    }
    for (int i = 1; i <= n * k; ++i)
        v[c[i]].push_back(i);

    vector<ban> u;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k - 1; ++j)
        {
            u.push_back(ban(v[i][j], v[i][j + 1], i));
        }
    }

    sort(all(u));

    for (int i = 0; i < sz(u); ++i)
    {
        if (a[u[i].g])
            continue;
        int maxu = 0;
        for (int j = u[i].l; j <= u[i].r; ++j)
        {
            maxu = max(maxu, q[j]);
        }
        ++maxu;
        if (maxu <= (n / (k - 1) + !!(n % (k - 1))))
        {
            a[u[i].g] = u[i].l;
            b[u[i].g] = u[i].r;
            for (int j = u[i].l; j <= u[i].r; ++j)
            {
                ++q[j];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!a[i])
            return false;
    }

    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 10004;
    while (st--)
    {
        n = rnf() % 50 + 1;
        k = rnf() % 50 + 2;
        for (int i = 1; i <= n * k; ++i)
        {
            c[i] = (i - 1) / k + 1;
        }
        for (int i = n * k; i >= 1; --i)
            swap(c[i], c[rnf() % i + 1]);
        if (!solv())
        {
            cout << "WA\n";
            cout << n << ' ' << k << "\n";
            for (int i = 1; i <= n * k; ++i)
                cout << c[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n * k; ++i)
                cout << q[i] << ' ';
            cout << "\n";
            solv();
            return 0;
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n * k; ++i)
            cin >> c[i];
        solv();
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ' << b[i] << "\n";
    }
    return 0;
}