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
const int N = 30004, INF = 1000000009;

int n;
int a[N], b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    b[0] = INF;
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= max(0, min(b[i - 1] - a[i - 1], a[i] - a[i - 1]));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
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