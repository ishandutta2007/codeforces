#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;
const long long M = 2500000000;
struct ban
{
    int i, x, y;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x / 1000 < b.x / 1000)
        return true;
    if (a.x / 1000 > b.x / 1000)
        return false;
    if ((a.x / 1000) % 2 == 0)
        return a.y < b.y;
    return a.y > b.y;
}

int n;
ban a[N];

int u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", a[i].i);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}