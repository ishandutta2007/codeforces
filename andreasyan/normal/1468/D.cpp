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

int n, m, a, b;
int s[N];

int u, t;

bool stg(int m)
{
    if (m > u - 1)
        return false;
    int tt = 1;
    for (int i = m; i >= 1; --i)
    {
        if (tt + s[i] > t)
            return false;
        ++tt;
    }
    return true;
}

void solv()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &s[i]);
    sort(s + 1, s + m + 1);

    u = abs(a - b);
    if (a < b)
        t = b - 1;
    else
        t = n - b;

    int ans = 0;
    int l = 1, r = m;
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
    printf("%d\n", ans);
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