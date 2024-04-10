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

int n, qq;
int a[N];

ll p[N];

set<ll> s;

void rec(int l, int r)
{
    if (l > r)
        return;

    s.insert(p[r] - p[l - 1]);

    int u;
    int ul = l, ur = r;
    while (ul <= ur)
    {
        int um = (ul + ur) / 2;
        if (a[um] <= (a[l] + a[r]) / 2)
        {
            u = um;
            ul = um + 1;
        }
        else
            ur = um - 1;
    }

    if (u != r)
        rec(l, u);
    rec(u + 1, r);
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    s.clear();
    rec(1, n);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        if (s.find(x) != s.end())
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}