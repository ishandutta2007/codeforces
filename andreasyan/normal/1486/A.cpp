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
const int N = 102;

int n;
ll a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < i)
        {
            printf("NO\n");
            return;
        }
        a[i + 1] += (a[i] - i);
    }
    printf("YES\n");
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