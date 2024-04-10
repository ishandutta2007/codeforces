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
const int N = 100005;

int n, k;
int a[N];

bool solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < k)
            a[i] = -1;
        else if (a[i] == k)
            a[i] = 0;
        else
            a[i] = 1;
    }
    for (int i = 2; i < n; ++i)
    {
        if (a[i] == -1 && a[i - 1] >= 0 && a[i + 1] >= 0)
            a[i] = 1;
    }
    for (int i = 3; i <= n; ++i)
    {
        if (a[i] == -1 && a[i - 1] >= 0 && a[i - 2] >= 0)
            a[i] = 1;
    }
    for (int i = n - 2; i >= 1; --i)
    {
        if (a[i] == -1 && a[i + 1] >= 0 && a[i + 2] >= 0)
            a[i] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 1 && a[i - 1] == 0)
            a[i] = 0;
    }
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] == 1 && a[i + 1] == 0)
            a[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
            return false;
    }
    return true;
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
    {
        if (solv())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}