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
const int N = 200005, M = 10000007;

int u[M];
void pre()
{
    for (int i = 2; i < M; ++i)
    {
        if (u[i])
            continue;
        u[i] = i;
        if (i * 1LL * i >= M)
            continue;
        for (int j = i * i; j < M; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n, k;
int a[N];

bool c[M];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        a[i] = 1;
        int q = 0;
        int v = 0;
        while (x > 1)
        {
            if (u[x] == v)
            {
                q ^= 1;
            }
            else
            {
                if (q)
                    a[i] *= v;
                v = u[x];
                q = 1;
            }
            x /= u[x];
        }
        if (q)
            a[i] *= v;
    }

    int ans = 1;
    int s = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[a[i]])
        {
            c[a[i]] = true;
        }
        else
        {
            for (int j = s; j < i; ++j)
                c[a[j]] = false;
            c[a[i]] = true;
            s = i;
            ++ans;
        }
    }
    for (int j = s; j <= n; ++j)
        c[a[j]] = false;

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}