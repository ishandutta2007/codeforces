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
const int N = 1000006;
struct ban
{
    int x, y;
    ll z;
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

struct line
{
    ll b, k;
    line(){}
    line(ll b, ll k)
    {
        this->b = b;
        this->k = k;
    }
    ll yat(ll x)
    {
        return b + k * x;
    }
};
double hat(const line& t1, const line& t2)
{
    return (t2.b - t1.b) / (double)(t1.k - t2.k);
}

ll dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a + 1, a + n + 1);
    deque<line> t;
    deque<double> v;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = a[i].x * 1LL * a[i].y - a[i].z;
        if (!t.empty())
        {
            int ans = 0;
            int l = 0, r = sz(v) - 1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (v[m] <= a[i].y)
                {
                    ans = m + 1;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            dp[i] = max(dp[i], a[i].x * 1LL * a[i].y - a[i].z + t[ans].yat(a[i].y));
        }
        while (t.size() >= 2 && hat(t.front(), line(dp[i], -a[i].x)) > v.front())
        {
            t.pop_front();
            v.pop_front();
        }
        if (!t.empty())
            v.push_front(hat(t.front(), line(dp[i], -a[i].x)));
        t.push_front(line(dp[i], -a[i].x));
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    printf("%lld\n", ans);
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