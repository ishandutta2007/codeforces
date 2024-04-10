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
const int s = 450;

int n;
int a[N];

int q[N];

int p[N];
int u[N * 2];

int qq;
void ave(int x, int y, int k)
{
    if (q[x] == k)
        --qq;
    q[x] += y;
    if (q[x] == k)
        ++qq;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        q[a[i]]++;

    int maxu = 0;
    for (int x = 1; x <= n; ++x)
        maxu = max(maxu, q[x]);
    int maxx = -1;
    for (int x = 1; x <= n; ++x)
    {
        if (q[x] == maxu)
        {
            if (maxx == -1)
                maxx = x;
            else
            {
                printf("%d\n", n);
                return;
            }
        }
    }

    int ans = 0;

    for (int x = 1; x <= n; ++x)
    {
        if (q[x] <= s)
            continue;
        if (x == maxx)
            continue;

        for (int i = 1; i <= n; ++i)
        {
            p[i] = p[i - 1];
            if (a[i] == x)
                --p[i];
            else if (a[i] == maxx)
                ++p[i];
        }

        for (int i = 0; i < N * 2; ++i)
            u[i] = N;
        u[N + p[0]] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (u[N + p[i]] == N)
                u[N + p[i]] = i;
            ans = max(ans, i - u[N + p[i]]);
        }
    }

    for (int k = 1; k <= s; ++k)
    {
        memset(q, 0, sizeof q);
        qq = 0;

        int l = 1;
        for (int r = 1; r <= n; ++r)
        {
            ave(a[r], 1, k);
            if (q[a[r]] > k)
            {
                while (a[l] != a[r])
                {
                    ave(a[l], -1, k);
                    ++l;
                }
                ave(a[l], -1, k);
                ++l;
            }
            if (qq > 1)
                ans = max(ans, r - l + 1);
        }
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
    solv();
    return 0;
}