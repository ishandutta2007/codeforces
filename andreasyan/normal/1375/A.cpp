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

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        a[i] = abs(a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
            a[i] *= (-1);
    }
    int q1 = 0, q2 = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i + 1] >= 0)
            ++q1;
        if (a[i] - a[i + 1] <= 0)
            ++q2;
    }
    assert(q1 >= (n - 1) / 2 && q2 >= (n - 1) / 2);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
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
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}