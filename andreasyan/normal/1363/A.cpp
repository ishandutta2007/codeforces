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

bool solv()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int z = 0, k = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0)
            ++z;
        else
            ++k;
    }
    for (int i = 1; i <= k; i += 2)
    {
        if (i + z >= m && i <= m)
            return true;
    }
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}