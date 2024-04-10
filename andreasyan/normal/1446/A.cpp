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
const int N = 200005;

int n;
ll m;
int a[N];

void solv()
{
    scanf("%d", &n);
    scanf("%lld", &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > m)
            continue;
        if (a[i] >= (m / 2) + (m % 2))
        {
            printf("1\n");
            printf("%d\n", i);
            return;
        }
    }

    ll s = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > m)
            continue;
        s += a[i];
        v.push_back(i);
        if (s >= (m / 2) + (m % 2))
        {
            printf("%d\n", sz(v));
            for (int i = 0; i < sz(v); ++i)
                printf("%d ", v[i]);
            printf("\n");
            return;
        }
    }

    printf("-1\n");
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