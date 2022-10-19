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
int a[N];

int q[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        q[i] = 0;

    int ans = 0;

    ++q[a[1]];
    ++q[a[n]];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            q[a[i]] += 2;
            ++ans;
        }
    }

    int maxx = 1;
    for (int x = 2; x <= n; ++x)
    {
        if (q[x] > q[maxx])
            maxx = x;
    }
    int qq = 0;
    for (int x = 1; x <= n; ++x)
        qq += q[x];

    int q1 = 0;
    int q2 = 0;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
            continue;
        if (a[i] != maxx && a[i + 1] != maxx)
            ++q1;
        else
            ++q2;
    }

    while (1)
    {
        if (q[maxx] <= qq - q[maxx] + 2)
        {
            printf("%d\n", ans);
            return;
        }
        if (q1)
        {
            --q1;
            qq += 2;
            ++ans;
        }
        else if (q2)
        {
            --q2;
            qq += 2;
            q[maxx]++;
            ++ans;
        }
        else
        {
            printf("-1\n");
            return;
        }
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
    {
        solv();
    }
    return 0;
}