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
int b[N], c[N];

ll a[N];

const int m = 33;
int q[m];

int bb[N], cc[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += b[i];
    for (int i = 1; i <= n; ++i)
        s += c[i];
    if (s % (2 * n) != 0)
    {
        printf("-1\n");
        return;
    }
    s /= (2 * n);
    for (int i = 1; i <= n; ++i)
    {
        if ((b[i] + c[i] - s) < 0 || (b[i] + c[i] - s) % n != 0)
        {
            printf("-1\n");
            return;
        }
        a[i] = (b[i] + c[i] - s) / n;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((a[i] & (1LL << j)))
                ++q[j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((a[i] & (1LL << j)))
            {
                bb[i] += (1LL << j) * q[j];
            }
        }
        for (int j = 0; j < m; ++j)
        {
            if ((a[i] & (1LL << j)))
            {
                cc[i] += (1LL << j) * n;
            }
            else
            {
                cc[i] += (1LL << j) * q[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (bb[i] != b[i] || cc[i] != c[i])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", a[i]);
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