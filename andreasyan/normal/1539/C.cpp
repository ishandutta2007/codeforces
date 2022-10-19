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

int n;
ll k, x;
ll a[N];

void solv()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    vector<ll> v;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
            v.push_back(0);
        else if ((a[i + 1] - a[i]) % x == 0)
            v.push_back((a[i + 1] - a[i]) / x - 1);
        else
            v.push_back((a[i + 1] - a[i]) / x);
    }

    sort(all(v));

    int ans = n;
    for (int i = 0; i < sz(v); ++i)
    {
        if (k >= v[i])
        {
            k -= v[i];
            --ans;
        }
        else
            break;
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