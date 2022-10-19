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
const int N = 100005, M = 1000000007;

int n;
int a[N];

int u[N];
void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        u[a[i]] = i;

    int l = min(u[0], u[1]);
    int r = max(u[0], u[1]);
    int ans = 1;
    for (int i = 2; i < n; ++i)
    {
        if (l < u[i] && u[i] < r)
            ans = (ans * 1LL * ((r - l + 1) - i)) % M;
        else
        {
            r = max(r, u[i]);
            l = min(l, u[i]);
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

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}