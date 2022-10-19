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
const int N = 500005;

int n;
int a[N];

pair<int, int> b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        b[i] = m_p(a[i], i);
    sort(b + 1, b + n + 1);
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    ll ans = 0;
    int u = 0;
    for (int ii = 0; ii < n - 2; ++ii)
    {
        int i = b[ii + 1].se;
        if (i == *s.begin() || i == *(--s.end()))
        {
            ans += (n - 2 - ii) * 1LL * (a[i] - u);
            u = a[i];
        }
        else
        {
            int x1 = *s.upper_bound(i);
            int x0 = *(--s.find(i));
            ans += (n - 3 - ii) * 1LL * (a[i] - u);
            ans += min(a[x0] - u, a[x1] - u);
            u = a[i];
        }
        s.erase(i);
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}