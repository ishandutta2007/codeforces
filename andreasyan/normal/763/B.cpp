#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 500005;

int n;
int x1[N], y1[N], x2[N], y2[N];

int main()
{
    scanf("%d", &n);
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        printf("%d\n", abs(x1[i] % 2) * 2 + abs(y1[i] % 2) + 1);
    }
    return 0;
}