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
const int N = 200005, M = 10000007, K = 22;

int u[M];
void pre()
{
    for (int i = 2; i < M; ++i)
    {
        if (u[i])
            continue;
        u[i] = i;
        if (i * 1LL * i >= M)
            continue;
        for (int j = i * i; j < M; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n, k;
int a[N];

/*int minu[N * 4];
int laz[N * 4];

void shi(int pos)
{
    if (!laz[pos])
        return;
    minu[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    minu[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}*/

int b[M];
int dp[N][K];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        a[i] = 1;
        int q = 0;
        int v = 0;
        while (x > 1)
        {
            if (u[x] == v)
            {
                q ^= 1;
            }
            else
            {
                if (q)
                    a[i] *= v;
                v = u[x];
                q = 1;
            }
            x /= u[x];
        }
        if (q)
            a[i] *= v;
    }

    set<int> s;
    s.insert(0);
    for (int i = 1; i <= n; ++i)
    {
        if (b[a[i]])
        {
            s.insert(b[a[i]]);
            while (sz(s) > k + 1)
                s.erase(s.begin());
        }
        b[a[i]] = i;

        for (int q0 = 0; q0 <= k; ++q0)
            dp[i][q0] = n;

        auto it = (--s.end());
        for (int q = 0; q <= k; ++q)
        {
            int j = *it;
            for (int q0 = 0; q0 <= k - q; ++q0)
                dp[i][q + q0] = min(dp[i][q + q0], dp[j][q0] + 1);
            if (it != s.begin())
                --it;
        }
    }

    for (int i = 1; i <= n; ++i)
        b[a[i]] = 0;

    cout << dp[n][k] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}