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
const int N = 1000006, M = 998244353;

int n, k;
int a[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = n; i >= n - k + 1; --i)
    {
        if (a[i] == 0 || a[i] == -1)
            a[i] = 0;
        else
        {
            cout << "0\n";
            return;
        }
    }

    int ans = 1;
    for (int i = 1; i <= k; ++i)
        ans = (ans * 1LL * i) % M;
    for (int i = 1; i <= n - k; ++i)
    {
        if (a[i] == 0)
            ans = (ans * 1LL * (k + 1)) % M;
        else if (a[i] == -1)
            ans = (ans * 1LL * (i + k)) % M;
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