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
const int N = 500005;

int n;
int a[N], x;

int d[N];
ll p[N];
ll minu[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= (n / 2 + n % 2); ++i)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    for (int i = (n / 2 + n % 2) + 1; i <= n; ++i)
        a[i] = x;
    for (int i = 1; i <= (n / 2 + 1); ++i)
    {
        d[i] = -a[i] + x;
        p[i] = p[i - 1] + d[i];
        minu[i] = min(minu[i - 1], p[i]);
    }
    ll s = 0;
    for (int i = 1; i <= (n / 2 + 1); ++i)
    {
        s += a[i];
    }
    for (int k = (n / 2 + 1); k <= n; ++k)
    {
        if (s + minu[n - k] > 0)
        {
            printf("%d\n", k);
            return;
        }
        s += a[k + 1];
    }
    printf("-1\n");
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