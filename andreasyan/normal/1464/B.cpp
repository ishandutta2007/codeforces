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
char a[N];
int x, y;

ll p0[N], p1[N], s0[N], s1[N];

int pq0[N], pq1[N], pq2[N];
int sq0[N], sq1[N], sq2[N];

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    scanf("%d%d", &x, &y);

    int q0 = 0, q1 = 0, q2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        p0[i] = p0[i - 1];
        p1[i] = p1[i - 1];
        if (a[i] == '0')
        {
            p0[i] += (q1 * 1LL * y);
            p1[i] += ((q1 + q2) * 1LL * y);
            ++q0;
        }
        else if (a[i] == '1')
        {
            p0[i] += ((q0 + q2) * 1LL * x);
            p1[i] += (q0 * 1LL * x);
            ++q1;
        }
        else
        {
            p0[i] += (q1 * 1LL * y);
            p1[i] += (q0 * 1LL * x);
            ++q2;
        }
        pq0[i] = q0;
        pq1[i] = q1;
        pq2[i] = q2;
    }

    s0[n + 1] = s1[n + 1] = 0;
    sq0[n + 1] = sq1[n + 1] = sq2[n + 1] = 0;
    q0 = q1 = q2 = 0;
    for (int i = n; i >= 1; --i)
    {
        s0[i] = s0[i + 1];
        s1[i] = s1[i + 1];
        if (a[i] == '0')
        {
            s0[i] += (q1 * 1LL * x);
            s1[i] += ((q1 + q2) * 1LL * x);
            ++q0;
        }
        else if (a[i] == '1')
        {
            s0[i] += ((q0 + q2) * 1LL * y);
            s1[i] += (q0 * 1LL * y);
            ++q1;
        }
        else
        {
            s0[i] += (q1 * 1LL * x);
            s1[i] += (q0 * 1LL * y);
            ++q2;
        }
        sq0[i] = q0;
        sq1[i] = q1;
        sq2[i] = q2;
    }

    ll ans = p0[n];
    for (int i = 0; i <= n; ++i)
    {
        ans = min(ans, p0[i] + s1[i + 1] + (pq0[i] + pq2[i]) * 1LL * (sq1[i + 1] + sq2[i + 1]) * x
                                         + (pq1[i]) * 1LL * (sq0[i + 1]) * y);
        ans = min(ans, p1[i] + s0[i + 1] + (pq0[i]) * 1LL * (sq1[i + 1]) * x
                                         + (pq1[i] + pq2[i]) * 1LL * (sq0[i + 1] + sq2[i + 1]) * y);
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
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}