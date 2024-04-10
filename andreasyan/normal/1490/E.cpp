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

struct ban
{
    int x, i;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

ll p[N];
int u[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].x);
        a[i].i = i;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i].x;

    for (int i = n; i >= 1; --i)
    {
        u[i] = i;

        int l = i + 1, r = n;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[i] >= a[m].x)
            {
                u[i] = u[m];
                l = m + 1;
            }
            else
                r = m - 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (u[i] == n)
            ans.push_back(a[i].i);
    }

    sort(all(ans));
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
    printf("\n");
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