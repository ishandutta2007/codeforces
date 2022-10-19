#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1000006;

int n, x, y;

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d%d", &n, &x, &y);
        printf("%d %d\n", min(n, max(1, x + y - n + 1)), max(1, min(n, x + y - 1)));
    }
    return 0;
}