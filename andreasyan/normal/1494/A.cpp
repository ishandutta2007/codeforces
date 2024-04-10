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
const int N = 55;

int n;
char a[N];

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;

    for (int x = 0; x < (1 << 3); ++x)
    {
        bool z = true;
        int p = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (a[i] - 'A'))))
                ++p;
            else
                --p;
            if (p < 0)
            {
                z = false;
                break;
            }
        }
        if (z && p == 0)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}