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

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int l = a[1] + 1, r = a[1] + 1;
    for (int i = 2; i < n; ++i)
    {
        l = max(l - k + 1, a[i] + 1);
        r = min(r + k - 1, a[i] + k);

        if (l > r)
        {
            printf("NO\n");
            return;
        }
    }

    if (l - k + 1 <= a[n] + 1 && a[n] + 1 <= r + k - 1)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}