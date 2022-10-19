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
struct ban
{
    ll x, y;
    ban()
    {
        x = y = 0;
    }
    ban(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

ll is(const ban& t1, const ban& t2, const ban& t3)
{
    return (t3.x - t1.x) * (t2.y - t1.y) - (t3.y - t1.y) * (t2.x - t1.x);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    for (int i = 1; i <= n; ++i)
        a[i].y -= a[i].x * a[i].x;
    sort(a + 1, a + n + 1);
    vector<ban> u;
    u.push_back(a[1]);
    for (int i = 2; i <= n; ++i)
    {
        if (i == n || is(a[1], a[n], a[i]) < 0)
        {
            while (sz(u) >= 2 && is(u[sz(u) - 2], u[sz(u) - 1], a[i]) <= 0)
                u.pop_back();
            u.push_back(a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < sz(u) - 1; ++i)
    {
        if (u[i].x < u[i + 1].x)
            ++ans;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}