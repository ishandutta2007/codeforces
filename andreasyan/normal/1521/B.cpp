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
const int N = 100005, M = 2000006;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int u[M];
void pre()
{
    u[1] = 1;
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

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int minu = a[1];
    for (int i = 1; i <= n; ++i)
        minu = min(minu, a[i]);

    int mini;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == minu)
        {
            mini = i;
            break;
        }
    }

    vector<pair<pair<int, int>, pair<int, int> > > ans;

    for (int i = 1; i <= n; ++i)
    {
        if (i == mini)
            continue;
        while (1)
        {
            int u = i - 1;
            if (u == 0)
                u = i + 1;
            if (!(gcd(a[i], a[u]) == 1 && gcd(a[i], minu) == 1))
                ++a[i];
            else
                break;
        }
        ans.push_back(m_p(m_p(i, mini), m_p(a[i], minu)));
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ' << ans[i].se.fi << ' ' << ans[i].se.se << "\n";
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