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

void solv()
{
    int x1, y1_, x2, y2;
    scanf("%d%d%d%d", &x1, &y1_, &x2, &y2);
    if (x1 == x2)
    {
        printf("%d\n", abs(y1_ - y2));
        return;
    }
    else if (y1_ == y2)
    {
        printf("%d\n", abs(x1 - x2));
        return;
    }
    printf("%d\n", abs(x1 - x2) + abs(y1_ - y2) + 2);
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