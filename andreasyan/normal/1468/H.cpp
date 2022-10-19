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

int n, k, m;
int a[N];

void solv()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);

    if ((n - m) % (k - 1) != 0)
    {
        printf("NO\n");
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        if ((a[i] - i) >= (k - 1) / 2 && (n - a[i] - (m - i)) >= (k - 1) / 2)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}