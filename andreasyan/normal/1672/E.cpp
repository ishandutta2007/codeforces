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
const int N = 2003;

int qry(int w)
{
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
}

int n;

void solv()
{
    cin >> n;

    int l = 1, r = N * N;
    int d;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(m) == 1)
        {
            d = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    int ans = d;
    for (int i = 2; i <= n; ++i)
    {
        int u = qry(d / i);
        if (u)
            ans = min(ans, (d / i) * u);
    }

    cout << "! " << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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