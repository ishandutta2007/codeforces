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

int n, k;

void solv()
{
    scanf("%d%d", &n, &k);

    if (n % 2 == 0)
        printf("%d\n", (k - 1) % n + 1);
    else
    {
        if (k < (n / 2 + 1))
            printf("%d\n", k);
        else
            printf("%d\n", (k + 1 + ((k - (n / 2 + 1)) / (n / 2)) - 1) % n + 1);
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
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}