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
ll p[N];

int t[N];
void ubd(int x)
{
    while (x <= n)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }

    ll ans = 0;

    vector<ll> v;
    for (int i = 1; i < n; ++i)
        v.push_back(p[i]);
    sort(all(v));
    for (int i = 1; i < n; ++i)
    {
        ubd(lower_bound(all(v), p[i]) - v.begin() + 1);
        ans += (i - qry(lower_bound(all(v), p[i]) - v.begin() + 1));
    }

    sort(p + 1, p + n);
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] - p[i - 1] < 0)
        {
            cout << "-1\n";
            return;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}