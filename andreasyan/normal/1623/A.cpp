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
const int N = 102;

int n, m, bx, by, kx, ky;

void solv()
{
    cin >> n >> m >> bx >> by >> kx >> ky;

    int ans = n * 2 + m + 2;

    if (bx <= kx)
        ans = min(ans, kx - bx);
    else
        ans = min(ans, n - bx + n - kx);

    if (by <= ky)
        ans = min(ans, ky - by);
    else
        ans = min(ans, m - by + m - ky);

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