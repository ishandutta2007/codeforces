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

int n, m;

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

void solv()
{
    scanf("%d%d", &n, &m);

    for (int x = 1; x <= n; ++x)
        p[x] = x;

    int mm = 0;
    for (int ii = 0; ii < m; ++ii)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y)
        {
            ++mm;
            continue;
        }
        kpc(x, y);
    }
    m -= mm;

    set<int> s;
    for (int x = 1; x <= n; ++x)
        s.insert(fi(x));

    printf("%d\n", m + m - n + sz(s));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}