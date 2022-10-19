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
#define int long long
const int M = 1000000007;

int ast(int x, ll n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int hat(int l1, int r1, int l2, int r2)
{
    return max(0LL, min(r1, r2) - max(l1, l2) + 1);
}

int n, m, k, r, c;
int ax, ay, bx, by;

void solv()
{
    cin >> n >> m >> k >> r >> c;
    cin >> ax >> ay >> bx >> by;

    if (ax == bx && ay == by)
    {
        cout << ast(k, n * m) << "\n";
        return;
    }

    ll h = hat(ax, ax + r - 1, bx, bx + r - 1) * hat(ay, ay + c - 1, by, by + c - 1);

    cout << (ast(k, r * c - h) * ast(k, n * m - 2 * r * c + h)) % M << "\n";
}

int32_t main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}