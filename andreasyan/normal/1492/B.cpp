#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;
const int N = 100005;

int n;
int a[N];

int maxu[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        maxu[i] = max(maxu[i - 1], a[i]);

    int u = n;
    while (u)
    {
        for (int j = u; ; --j)
        {
            if (a[j] == maxu[u])
            {
                for (int k = j; k <= u; ++k)
                    printf("%d ", a[k]);
                u = j - 1;
                break;
            }
        }
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}