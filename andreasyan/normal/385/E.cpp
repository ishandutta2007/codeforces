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

int n, sx, sy, dx, dy;
ll t;

struct ban
{
    vector<int> a[6];
    ban()
    {
        for (int i = 0; i < 6; ++i)
            a[i].assign(6, 0);
    }
};

ban operator*(const ban& a, const ban& b)
{
    ban ans;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < 6; ++k)
            {
                ans.a[i][j] = (ans.a[i][j] + a.a[i][k] * 1LL * b.a[k][j]) % n;
            }
        }
    }
    return ans;
}

ban ast(ban x, ll n)
{
    ban ans;
    for (int i = 0; i < 6; ++i)
    {
        ans.a[i][i] = 1;
    }
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

void solv()
{
    cin >> n >> sx >> sy >> dx >> dy >> t;
    --sx;
    --sy;
    dx = (dx % n + n) % n;
    dy = (dy % n + n) % n;
    // x y dx dy t 1
    ban u;
    u.a[0] = {2, 1, 1, 0, 1, 2};
    u.a[1] = {1, 2, 0, 1, 1, 2};
    u.a[2] = {1, 1, 1, 0, 1, 2};
    u.a[3] = {1, 1, 0, 1, 1, 2};
    u.a[4] = {0, 0, 0, 0, 1, 1};
    u.a[5] = {0, 0, 0, 0, 0, 1};
    u = ast(u, t);
    ll x = (sx * 1LL * u.a[0][0]) % n + (sy * 1LL * u.a[0][1]) % n + (dx * 1LL * u.a[0][2]) % n + (dy * 1LL * u.a[0][3]) % n + u.a[0][5];
    x %= n;
    ll y = (sx * 1LL * u.a[1][0]) % n + (sy * 1LL * u.a[1][1]) % n + (dx * 1LL * u.a[1][2]) % n + (dy * 1LL * u.a[1][3]) % n + u.a[1][5];
    y %= n;
    printf("%lld %lld\n", x + 1, y + 1);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}