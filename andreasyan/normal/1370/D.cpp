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
const int N = 200005, INF = 1000000009;

int n, k;
int a[N];

bool stgz(int x)
{
    int u = -1;
    int q = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] <= x && u != i - 1)
        {
            if ((k % 2 == 0) || (k % 2 == 1 && i < n))
            {
                u = i;
                ++q;
            }
        }
    }
    return (q >= (k / 2));
}

bool stgk(int x)
{
    int u = -1;
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= x && u != i - 1)
        {
            if ((k % 2 == 1) || (k % 2 == 0 && i < n))
            {
                u = i;
                ++q;
            }
        }
    }
    return (q >= (k / 2) + (k % 2));
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int ansz;
    int l = 1, r = INF;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stgz(m))
        {
            ansz = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    int ansk;
    l = 1, r = INF;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stgk(m))
        {
            ansk = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", min(ansz, ansk));
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}