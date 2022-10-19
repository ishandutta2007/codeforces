#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;

int ast(int x, int m)
{
    int ans = 1;
    while (m)
    {
        if (m % 2 == 1)
            ans = (ans * 1LL * x) % n;
        x = (x * 1LL * x) % n;
        m /= 2;
    }
    return ans;
}

int a[N];

bool cp[N];
bool c[N];

void rec(int i, int p)
{
    if (i == n + 1)
    {
        printf("YES\n");
        for (int i = 1; i <= n; ++i)
            printf("%d\n", a[i]);
        /*int p = 1;
        for (int i = 1; i <= n; ++i)
        {
            p = (p * 1LL * a[i]) % n;
            printf("%d ", p);
        }
        printf("\n");*/
        exit(0);
        return;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (c[j])
            continue;
        int pp = (p * 1LL * j) % n;
        if (cp[pp])
            continue;
        a[i] = j;
        c[j] = cp[pp] = true;
        rec(i + 1, pp);
        c[j] = cp[pp] = false;
    }
}

void por()
{
    scanf("%d", &n);
    rec(1, 1);
}

void solv()
{
    scanf("%d", &n);
    if (n == 4 || n == 1)
    {
        rec(1, 1);
    }
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    a[n] = n;
    a[1] = 1;
    for (int i = 2; i < n; ++i)
        a[i] = (i * 1LL * ast(i - 1, n - 2)) % n;
    for (int i = 1; i <= n; ++i)
        printf("%d\n", a[i]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //por();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}