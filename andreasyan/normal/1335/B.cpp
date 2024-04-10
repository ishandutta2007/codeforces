#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;

int n, a, b;

char ans[N];

void solv()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; ++i)
    {
        ans[i] = min(i, b - 1) + 'a';
    }
    for (int i = a; i < n; ++i)
        ans[i] = ans[i - a];
    ans[n] = 0;
    printf("%s\n", ans);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}