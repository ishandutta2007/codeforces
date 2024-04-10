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
    int x1, y1_, x2, y2;
};

int n;
ban a[N];

bool operator<(const ban& a, const ban& b)
{
    if (a.x1 == a.x2 && b.x1 != b.x2)
        return true;
    if (a.x1 != a.x2 && b.x1 == b.x2)
        return false;
    if (a.x1 == a.x2 && b.x1 == b.x2)
        return false;

    if (a.y1_ == a.y2 && b.y1_ != b.y2)
        return true;
    if (a.y1_ != a.y2 && b.y1_ == b.y2)
        return false;
    if (a.y1_ == a.y2 && b.y1_ == b.y2)
        return false;

    bool z = true;
    if ((b.x2 - b.x1) < 0)
        z ^= true;
    if ((a.x2 - a.x1) < 0)
        z ^= true;
    if (z)
        return (a.y2 - a.y1_) * 1LL * (b.x2 - b.x1) < (b.y2 - b.y1_) * 1LL * (a.x2 - a.x1);
    return (a.y2 - a.y1_) * 1LL * (b.x2 - b.x1) > (b.y2 - b.y1_) * 1LL * (a.x2 - a.x1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1_, &a[i].x2, &a[i].y2);
    sort(a + 1, a + n + 1);

    ll ans = 0;
    int q1 = 0, q2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || (a[i].y2 - a[i].y1_) * 1LL * (a[i - 1].x2 - a[i - 1].x1) != (a[i - 1].y2 - a[i - 1].y1_) * 1LL * (a[i].x2 - a[i].x1))
        {
            ans += q1 * 1LL * q2;
            q1 = q2 = 0;
        }
        if (m_p(a[i].x1, a[i].y1_) < m_p(a[i].x2, a[i].y2))
            ++q1;
        else
            ++q2;
    }
    ans += q1 * 1LL * q2;

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}