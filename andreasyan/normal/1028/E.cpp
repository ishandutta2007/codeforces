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
const int N = 200005, INF = 1000000009;

int n;
int b[N];

ll a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    bool z = true;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != b[0])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        if (b[0] == 0)
        {
            printf("YES\n");
            for (int i = 0; i < n; ++i)
                printf("1 ");
            printf("\n");
        }
        else
            printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
    {
        if (b[(i - 1 + n) % n] < b[i])
        {
            a[i] = b[i];
            for (int j = i - 1; j >= 0; --j)
            {
                a[j] = b[j] + (b[(j - 1 + n) % n] / a[(j + 1) % n] + 1) * a[(j + 1) % n];
            }
            for (int j = n - 1; j > i; --j)
            {
                a[j] = b[j] + (b[(j - 1 + n) % n] / a[(j + 1) % n] + 1) * a[(j + 1) % n];
            }
            for (int i = 0; i < n; ++i)
                printf("%lld ", a[i]);
            printf("\n");
            return;
            for (int i = 0; i < n; ++i)
                printf("%lld ", (a[i] % a[(i + 1) % n]));
            printf("\n");
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}