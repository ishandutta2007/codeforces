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
const int INF = 1000000009, k = 30;

int n, m;

bool stg(int x)
{
    --x;
    int y = 0;
    for (int i = k - 1; i >= 0; --i)
    {
        if ((n & (1 << i)))
            continue;
        if ((y | (1 << i)) <= x)
            y |= (1 << i);
    }

    return ((n ^ y) <= m);
}

void solv()
{
    cin >> n >> m;

    int ans = 0;
    int l = 1, r = INF;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
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

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}