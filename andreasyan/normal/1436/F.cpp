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
const int N = 100005, M = 998244353;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

struct ban
{
    ll x;
    ban()
    {
        x = 0;
    }
    ban(ll x)
    {
        this->x = x % M;
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
ban ast(ban x, ll n)
{
    ban ans(1);
    while (n)
    {
        if (n % 2 == 1)
            ans = ans * x;
        x = x * x;
        n /= 2;
    }
    return ans;
}

ban solv0(vector<int> v)
{
    ban ans;
    for (int x = 1; x < (1 << sz(v)); ++x)
    {
        int g = 0;
        int s = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                s += v[i];
                g = gcd(g, v[i]);
            }
        }
        if (g == 1)
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if ((x & (1 << i)))
                {
                    ans = ans + ban(s) * ban(s - v[i]);
                }
            }
        }
    }
    return ans;
}

int m;
int a[N];

ban ans[N];

ban f(ll q)
{
    ban ans(0);
    if (q == 0)
        return ans;
    ans = ans + ast(ban(2), q) - ban(1);
    ans = ans + ast(ban(2), q - 1) * (q - 1);
    ans = ans - (ast(ban(2), q - 1) - ban(1));
    return ans;
}

void solv()
{
    scanf("%d", &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x] = y;
    }

    /*vector<int> v;
    for (int x = 1; x < N; ++x)
    {
        for (int i = 0; i < a[x]; ++i)
            v.push_back(x);
    }
    printf("%lld\n", solv0(v).x);*/

    for (int x = N - 1; x >= 1; --x)
    {
        ll q = 0;
        ban s;
        for (int i = x; i < N; i += x)
        {
            q += a[i];
            s = s + ban(a[i]) * ban(i);
        }

        if (q < 2)
            continue;

        ban yans;
        ban yans1;
        for (int i = x; i < N; i += x)
        {
            yans = yans + ban(a[i]) * (s - ban(i)) * ban(i);
            yans1 = yans1 + ban(a[i]) * ban(i) * ban(i);
        }
        ans[x] = ans[x] + f(q - 2) * yans;
        ans[x] = ans[x] + f(q - 1) * yans1;
        ans[x] = ans[x] + ast(2, q - 2) * yans;

        for (int i = x + x; i < N; i += x)
        {
            ans[x] = ans[x] - ans[i];
        }
    }

    printf("%lld\n", ans[1].x);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}