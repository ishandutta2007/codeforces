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

int n;

int qry(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

void solv()
{
    scanf("%d", &n);

    int u = qry(1, n);

    if (u == n || qry(u, n) != u)
    {
        int l = 1, r = u - 1;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(m, u) == u)
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }
    else
    {
        int l = u + 1, r = n;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(u, m) == u)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        printf("! %d\n", ans);
        fflush(stdout);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}