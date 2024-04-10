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

int s[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
            v.push_back(i);
    }

    s[n + 1] = 0;
    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1];
        if (a[i] == 0)
            ++s[i];
    }

    int ans = sz(v);
    for (int i = 0; i < sz(v); ++i)
    {
        ans = min(ans, i + max(0, s[v[i]] - i));
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