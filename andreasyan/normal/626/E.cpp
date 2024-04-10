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
const int N = 200005;
const double EPS = 0.0000000001;

struct ban
{
    ll x, y;
    ban()
    {
        x = 0;
        y = 1;
    }
    ban(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return (a.x * b.y) < (b.x * a.y);
}
bool operator==(const ban& a, const ban& b)
{
    return (a.x == b.x && a.y == b.y);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x * b.y - b.x * a.y, a.y * b.y);
}

int n;
int a[N];

ll p[N];

ban stg(int i, int m)
{
    ll s = p[n] - p[n - m];
    s += a[i];
    s += p[i - 1] - p[i - 1 - m];
    return ban(s, (1 + m * 2));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    ban yans = ban(-1, 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = min(i - 1, n - i);
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m == min(i - 1, n - i) || stg(i, m + 1) < stg(i, m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        if (yans < stg(i, ans) - ban(a[i], 1))
            yans = stg(i, ans) - ban(a[i], 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = min(i - 1, n - i);
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m == min(i - 1, n - i) || stg(i, m + 1) < stg(i, m))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        if (yans == stg(i, ans) - ban(a[i], 1))
        {
            vector<int> v;
            for (int j = i; j >= i - ans; --j)
                v.push_back(a[j]);
            for (int j = n; j >= n - ans + 1; --j)
                v.push_back(a[j]);
            printf("%d\n", v.size());
            for (int i = 0; i < v.size(); ++i)
                printf("%d ", v[i]);
            printf("\n");
            return;
        }
    }
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