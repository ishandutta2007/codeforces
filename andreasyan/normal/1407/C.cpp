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
const int N = 10004;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    int maxi = 1;
    for (int i = 2; i <= n; ++i)
    {
        int q1, q2;
        printf("? %d %d\n", maxi, i);
        fflush(stdout);
        scanf("%d", &q1);

        printf("? %d %d\n", i, maxi);
        fflush(stdout);
        scanf("%d", &q2);

        if (q1 < q2)
        {
            a[i] = q2;
        }
        else
        {
            a[maxi] = q1;
            maxi = i;
        }
    }
    a[maxi] = n;
    printf("! ");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}