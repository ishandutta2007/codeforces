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
const int N = 500005;

bool solv()
{
    int c1, c2, c3;
    int a1, a2, a3, a4, a5;

    scanf("%d%d%d", &c1, &c2, &c3);
    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);

    c1 -= a1;
    c2 -= a2;
    c3 -= a3;

    if (c1 < 0 || c2 < 0 || c3 < 0)
        return false;

    a4 = max(0, a4 - c1);
    a5 = max(0, a5 - c2);

    c3 -= a4;
    c3 -= a5;

    return c3 >= 0;
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
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}