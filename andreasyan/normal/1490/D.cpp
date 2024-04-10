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
const int N = 102;

int n;
int a[N];

int ans[N];
void rec(int l, int r, int d)
{
    if (l > r)
        return;
    int maxu = 0, maxi;
    for (int i = l; i <= r; ++i)
    {
        if (a[i] > maxu)
        {
            maxu = a[i];
            maxi = i;
        }
    }
    ans[maxi] = d;
    rec(l, maxi - 1, d + 1);
    rec(maxi + 1, r, d + 1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    rec(1, n, 0);

    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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