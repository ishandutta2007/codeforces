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
const int N = 100005;

int n, qq;
int a[N];

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int q = 0;
    for (int i = 1; i <= n; ++i)
        q += a[i];

    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int i;
            scanf("%d", &i);
            if (a[i] == 1)
                --q;
            else
                ++q;
            a[i] ^= 1;
        }
        else
        {
            int k;
            scanf("%d", &k);
            if (q >= k)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}