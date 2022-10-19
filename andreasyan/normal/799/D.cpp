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

int h0, w0, h, w, n;
int a[N];

ll ast[40];

int u1, u2;

bool stg(int q)
{
    if (q >= 34)
        return true;

    int q2 = 0;
    vector<int> v;
    for (int i = 1; i <= q; ++i)
    {
        if (a[i] >= 3)
            v.push_back(a[i]);
        else
            ++q2;
    }

    if (sz(v) >= 20)
        return true;

    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        int a1 = 1;
        int a2 = 1;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                a1 = min(u1 * 1LL, a1 * 1LL * v[i]);
            }
            else
            {
                a2 = min(u2 * 1LL, a2 * 1LL * v[i]);
            }
        }
        for (int i = 0; i <= q2; ++i)
        {
            if (a1 * ast[i] >= u1 && a2 * ast[q2 - i] >= u2)
                return true;
        }
    }
    return false;
}

int solvv()
{
    u1 = h0 / h + !!(h0 % h);
    u2 = w0 / w + !!(w0 % w);

    int l = 0, r = n;
    int ans = N;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return ans;
}

void solv()
{
    cin >> h0 >> w0 >> h >> w >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int ans = N;
    ans = min(ans, solvv());
    swap(h, w);
    ans = min(ans, solvv());

    if (ans == N)
        ans = -1;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    ast[0] = 1;
    for (int i = 1; i < 40; ++i)
        ast[i] = ast[i - 1] * 2;

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}