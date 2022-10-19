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

int n, x;
int a[N];

void solv()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x == 0 && mp[a[i] / x] != 0)
        {
            --mp[a[i] / x];
        }
        else
        {
            ++mp[a[i]];
        }
    }

    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
        ans += it->se;

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