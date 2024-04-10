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
int a[N];

int q[N];

void solv()
{
    memset(q, 0, sizeof q);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        q[a[i]]++;
    }

    int ans = 0;
    for (int s = 1; s <= n + n; ++s)
    {
        int yans = 0;
        for (int i = 1; i + i <= s; ++i)
        {
            if (i + i == s)
                yans += (q[i] / 2);
            else
                yans += min(q[i], q[s - i]);
        }
        ans = max(ans, yans);
    }

    printf("%d\n", ans);
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}