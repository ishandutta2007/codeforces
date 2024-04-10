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
int a[4], ca[4];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < 4; ++i)
        ca[i] = a[i];

    for (int x = 0; x < (1 << 4); ++x)
    {
        for (int i = 0; i < 4; ++i)
            a[i] = ca[i];

        for (int i = 0; i < 4; ++i)
        {
            if ((x & (1 << i)))
            {
                a[i]--;
                a[(i + 1) % 4]--;
            }
        }
        bool z = true;
        for (int i = 0; i < 4; ++i)
        {
            if (!(0 <= a[i] && a[i] <= n - 2))
            {
                z = false;
                break;
            }
        }
        if (z)
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