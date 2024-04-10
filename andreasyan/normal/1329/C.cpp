#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 23;

int h, g;
int a[(1 << N)];

int uf(int x)
{
    if (a[x * 2] == 0 && a[x * 2 + 1] == 0)
        return x;
    if (a[x * 2] > a[x * 2 + 1])
        return uf(x * 2);
    return uf(x * 2 + 1);
}

void f(int x)
{
    if (a[x * 2] == 0 && a[x * 2 + 1] == 0)
    {
        a[x] = 0;
        return;
    }
    if (a[x * 2] > a[x * 2 + 1])
    {
        a[x] = a[x * 2];
        f(x * 2);
    }
    else
    {
        a[x] = a[x * 2 + 1];
        f(x * 2 + 1);
    }
}

void solv()
{
    scanf("%d%d", &h, &g);
    for (int i = 1; i < (1 << (h + 1)); ++i)
        a[i] = 0;
    long long yans = 0;
    for (int i = 1; i < (1 << h); ++i)
    {
        scanf("%d", &a[i]);
        yans += a[i];
    }
    vector<int> ans;
    for (int i = 1; i < (1 << h); ++i)
    {
        while (1)
        {
            if (!a[i])
                break;
            int u = uf(i);
            if (u <= (1 << g) - 1)
                break;
            ans.push_back(i);
            yans -= a[i];
            f(i);
        }
    }
    printf("%lld\n", yans);
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
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