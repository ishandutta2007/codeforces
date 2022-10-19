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
const int N = 55;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = a[2] - a[1];
    for (int i = 2; i <= n; ++i)
        ans = min(ans, a[i] - a[i - 1]);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}