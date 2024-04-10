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
const int N = 400005;

int n;
int a[N];

const int m = 20;
int mini[N][m];
int u[N];

void pre()
{
    for (int i = 1; i <= n * 2; ++i)
    {
        mini[i][0] = i;
        for (int j = 1; i - (1 << j) + 1 >= 1; ++j)
        {
            int k1 = mini[i][j - 1];
            int k2 = mini[i - (1 << (j - 1))][j - 1];
            if (a[k1] < a[k2])
                mini[i][j] = k1;
            else
                mini[i][j] = k2;

            u[i] = j;
        }
    }
}

int qry(int l, int r)
{
    int t = u[r - l + 1];
    int k1 = mini[r][t];
    int k2 = mini[l + (1 << t) - 1][t];

    if (a[k1] < a[k2])
        return k1;
    return k2;
}

int rec(int l, int r)
{
    if (l > r)
        return 0;

    int m = qry(l, r);
    return max(rec(l, m - 1), rec(m + 1, r)) + 1;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = n + 1; i <= n * 2; ++i)
        a[i] = a[i - n];
    pre();

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            v.push_back((n - i + 1) % n);
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        v.push_back((v.back() - 1 + n) % n);
    }

    int l = 0, r = n - 1;
    while (r - l > 3)
    {
        int m = (l + r) / 2;

        int ul = v[m] + 1;
        int ur = ul + n - 1;
        int um = qry(ul, ur);

        if (rec(ul, um - 1) < rec(um + 1, ur))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    int ans = N;
    int ansi;
    for (int i = max(0, l - 2); i <= min(n - 1, r + 2); ++i)
    {
        int ul = v[i] + 1;
        int ur = ul + n - 1;

        int yans = rec(ul, ur);
        if (yans < ans)
        {
            ans = yans;
            ansi = v[i];
        }
    }

    cout << ans << ' ' << ansi << "\n";
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