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
const int N = 200005, M = 998244353;

int n, m;
int a[N], b[N];

int q[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    int minu = a[n];
    int j = m;
    for (int i = n; i >= 1; --i)
    {
        minu = min(minu, a[i]);
        while (minu < b[j])
            --j;
        if (minu == b[j])
            ++q[j];
    }
    if (minu != b[1])
    {
        printf("0\n");
        return;
    }
    int ans = 1;
    for (int i = 2; i <= m; ++i)
    {
        ans = (ans * 1LL * q[i]) % M;
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}