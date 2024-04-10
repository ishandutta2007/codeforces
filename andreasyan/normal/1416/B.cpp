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

vector<pair<pair<int, int>, int> > ans;
void ubd(int i, int j, int x)
{
    ans.push_back(m_p(m_p(i, j), x));
    a[i] -= x * i;
    a[j] += x * i;
}

void solv()
{
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];
    if (s % n != 0)
    {
        printf("-1\n");
        return;
    }
    s /= n;
    for (int i = 2; i <= n; ++i)
    {
        int x = (a[i] - s) / i;
    }
    for (int i = 2; i <= n; ++i)
    {
        ubd(1, i, (i - (a[i] % i)) % i);
        assert(a[i] % i == 0);
        ubd(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; ++i)
    {
        ubd(1, i, s);
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
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