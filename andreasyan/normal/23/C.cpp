#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 200005;

struct ban
{
    int i;
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

void solv()
{
    scanf("%d", &n);
    ll sx = 0, sy = 0;
    for (int i = 1; i <= n * 2 - 1; ++i)
    {
        a[i].i = i;
        scanf("%d%d", &a[i].x, &a[i].y);
        sx += a[i].x;
        sy += a[i].y;
    }
    sort(a + 1, a + n * 2 - 1 + 1);

    printf("YES\n");

    ll s = 0;
    for (int i = 1; i <= n * 2 - 1; i += 2)
    {
        s += a[i].y;
    }
    if (s * 2 >= sy)
    {
        for (int i = 1; i <= n * 2 - 1; i += 2)
        {
            printf("%d ", a[i].i);
        }
        printf("\n");
    }
    else
    {
        for (int i = 2; i <= n * 2 - 1; i += 2)
        {
            printf("%d ", a[i].i);
        }
        printf("%d ", a[n * 2 - 1].i);
        printf("\n");
    }
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}