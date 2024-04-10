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
char b[N];

void solv()
{
    cin >> n;
    cin >> (a + 1) >> (b + 1);

    int t[2] = {};
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[i])
            ++t[a[i] - '0'];
    }

    int ans = N;

    if ((t[0] + t[1]) % 2 == 0)
    {
        if (t[0] == t[1])
            ans = min(ans, t[0] + t[1]);
    }

    int h[2] = {};
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == b[i])
            ++h[a[i] - '0'];
    }

    if ((h[0] + h[1]) % 2 == 1)
    {
        if (h[1] == h[0] + 1)
            ans = min(ans, h[0] + h[1]);
    }

    if (ans == N)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}