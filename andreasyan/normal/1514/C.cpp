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
const int N = 100005, M = 1000000007;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;

void solv()
{
    cin >> n;

    /*vector<int> v;
    for (int x = 0; x < (1 << n); ++x)
    {
        vector<int> yv;
        int u = 1;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                u = (u * (i + 1)) % n;
                yv.push_back(i + 1);
            }
        }
        if (u == 1)
        {
            if (sz(yv) > sz(v))
                v = yv;
        }
    }

    for (int i = 0; i < sz(v); ++i)
    {
        cout << v[i] << ' ';
    }
    cout << "\n";*/

    vector<int> ans;
    int p = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (gcd(n, i) == 1)
        {
            p = (p * 1LL * i) % n;
            ans.push_back(i);
        }
    }

    if (p != 1)
        ans.pop_back();

    cout << sz(ans) << "\n";
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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