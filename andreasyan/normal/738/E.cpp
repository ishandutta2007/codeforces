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

int n, r;
int a[N];

int q[N];
int s[N];

void solv()
{
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    int ans = N;

    for (int i = 1; i <= n; ++i)
    {
        if (i == r)
            continue;
        ++q[a[i]];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = s[i + 1] + q[i];
    }

    int qq = 0;
    for (int d = 1; d < n; ++d)
    {
        if (q[d])
            --q[d];
        else
            ++qq;

        int yans = 0;
        if (a[r] != 0)
            ++yans;
        yans += (s[d + 1] + q[0]);
        yans += max(0, qq - (s[d + 1] + q[0]));

        ans = min(ans, yans);
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}