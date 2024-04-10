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

int n, k;
int a[N];

int p[N];
int minu[N];
bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] >= x)
            ++p[i];
        minu[i] = 2 * p[i] - i;
        minu[i] = min(minu[i], minu[i - 1]);
    }

    for (int i = k; i <= n; ++i)
    {
        if (2 * p[i] - i > minu[i - k])
            return true;
    }
    return false;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int l = 1, r = n;
    int ans;
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

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}