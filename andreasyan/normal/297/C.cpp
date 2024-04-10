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

int n;
pair<int, int> s[N];

int a[N], b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        s[i].se = i;
        scanf("%d", &s[i].fi);
    }
    sort(s + 1, s + n + 1);
    int s1 = 1;
    int s2 = n / 3 + !!(n % 3) + 1;
    int s3 = s2 + n / 3 + !!(n % 3);
    for (int i = s1; i < s2; ++i)
    {
        a[s[i].se] = i - 1;
        b[s[i].se] = s[i].fi - a[s[i].se];
    }
    for (int i = s2; i < s3; ++i)
    {
        b[s[i].se] = i - 1;
        a[s[i].se] = s[i].fi - b[s[i].se];
    }
    for (int i = s3; i <= n; ++i)
    {
        b[s[i].se] = max(0, min(s[i].fi, n - i));
        a[s[i].se] = s[i].fi - b[s[i].se];
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}