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

void solv()
{
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;

    if (sx - 1 <= d && sy - 1 <= d)
    {
        cout << "-1\n";
        return;
    }
    if (n - sx <= d && m - sy <= d)
    {
        cout << "-1\n";
        return;
    }
    if (sx - 1 <= d && n - sx <= d)
    {
        cout << "-1\n";
        return;
    }
    if (sy - 1 <= d && m - sy <= d)
    {
        cout << "-1\n";
        return;
    }

    cout << n - 1 + m - 1 << "\n";
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