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
const int N = 100005, INF = 1000000009;

int n, p;
int a[N];

int stg(int s)
{
    int maxu = 0;
    int x = s;
    int i = 1;
    int q = 0;
    while (1)
    {
        if (i <= n && a[i] <= x)
        {
            ++q;
            ++i;
            continue;
        }
        maxu = max(maxu, q);
        if (q == 0)
        {
            if (i <= n)
                return -1;
            break;
        }
        --q;
        ++x;
    }
    if (maxu < p)
    {
        return 0;
    }
    return 1;
}

void solv()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r = INF;
    int ul = INF;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m) < 0)
        {
            l = m + 1;
        }
        else
        {
            ul = m;
            r = m - 1;
        }
    }
    l = 1, r = INF;
    int ur = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m) > 0)
        {
            r = m - 1;
        }
        else
        {
            ur = m;
            l = m + 1;
        }
    }
    if (ul > ur)
    {
        printf("0\n");
        return;
    }
    printf("%d\n", ur - ul + 1);
    for (int i = ul; i <= ur; ++i)
        printf("%d ", i);
    printf("\n");
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