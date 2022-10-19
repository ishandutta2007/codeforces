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
const int N = 55;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> p, m;
    int ps = 0, ms = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= 0)
        {
            p.push_back(a[i]);
            ps += a[i];
        }
        else
        {
            m.push_back(a[i]);
            ms += a[i];
        }
    }
    sort(all(p));
    reverse(all(p));
    if (ps == -ms)
    {
        printf("NO\n");
    }
    else if (ps > -ms)
    {
        printf("YES\n");
        for (int i = 0; i < sz(p); ++i)
            printf("%d ", p[i]);
        for (int i = 0; i < sz(m); ++i)
            printf("%d ", m[i]);
        printf("\n");
    }
    else
    {
        printf("YES\n");
        for (int i = 0; i < sz(m); ++i)
            printf("%d ", m[i]);
        for (int i = 0; i < sz(p); ++i)
            printf("%d ", p[i]);
        printf("\n");
    }
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