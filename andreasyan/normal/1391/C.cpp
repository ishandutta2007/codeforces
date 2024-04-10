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
const int M = 1000000007;

int n;

void solv()
{
    scanf("%d", &n);
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = (ans * 1LL * i) % M;
    int u = 1;
    for (int i = 1; i <= n - 1; ++i)
        u = (u * 2) % M;
    ans = (ans - u + M) % M;
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