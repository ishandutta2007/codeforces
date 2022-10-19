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

int n;
int a[N];

vector<pair<int, int> > ans;
void ubd(int x, int y)
{
    ans.push_back(m_p(x, y));
    a[x] = (a[x] / a[y] + !!(a[x] % a[y]));
}

void solv()
{
    ans.clear();
    for (int i = 1; i <= n; ++i)
        a[i] = i;

    if (n <= 16)
    {
        for (int i = 3; i < n; ++i)
            ubd(i, n);
        while (a[n] != 1)
        {
            ubd(n, 2);
        }
    }
    else
    {
        for (int i = 3; i < n; ++i)
        {
            if (i == 16)
                continue;
            ubd(i, n);
        }
        while (1)
        {
            if (a[n] == 1 || a[16] == 1)
                break;
            if (a[n] < a[16])
                ubd(16, n);
            else
                ubd(n, 16);
        }
        while (1)
        {
            if (a[n] == 1 && a[16] == 1)
                break;
            if (a[n] > 1)
                ubd(n, 2);
            else
                ubd(16, 2);
        }
    }

    assert(sz(ans) <= n + 5);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*int x, y;
    scanf("%d%d", &x, &y);

    int q = 7;
    while (q--)
    {
        printf("%d %d\n", x, y);
        if (x < y)
            y = (y / x + !!(y % x));
        else
            x = (x / y + !!(x % y));
    }*/

    /*for (n = 1; n <= 20; ++n)
        solv();*/

    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d", &n);
        solv();
    }
    return 0;
}