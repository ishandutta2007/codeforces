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
const int N = 20000007;

int q[N];
int ast[30];
void pre()
{
    for (int i = 2; i < N; ++i)
    {
        if (q[i])
            continue;
        for (int j = i; j < N; j += i)
            ++q[j];
    }
    ast[0] = 1;
    for (int i = 1; i < 30; ++i)
        ast[i] = ast[i - 1] * 2;
}

void solv()
{
    int c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    for (int g = 1; g * g <= x; ++g)
    {
        if (x % g != 0)
            continue;
        {
            int u = x / g + d;
            if (u % c == 0)
            {
                u /= c;
                ans += ast[q[u]];
            }
        }
        if (g * g != x)
        {
            g = x / g;

            int u = x / g + d;
            if (u % c == 0)
            {
                u /= c;
                ans += ast[q[u]];
            }

            g = x / g;
        }
    }

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