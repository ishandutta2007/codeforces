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
char a[N], b[N];

void solv()
{
    cin >> n;
    cin >> (a + 1) >> (b + 1);

    if (a[1] != b[1] || a[n] != b[n])
    {
        cout << "-1\n";
        return;
    }

    vector<pair<int, int> > va;
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[j])
        {
            va.push_back(m_p(j, i - 1));
            j = i;
        }
    }
    va.push_back(m_p(j, n));

    vector<pair<int, int> > vb;
    j = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != b[j])
        {
            vb.push_back(m_p(j, i - 1));
            j = i;
        }
    }
    vb.push_back(m_p(j, n));

    if (sz(va) != sz(vb))
    {
        cout << "-1\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i < sz(va); ++i)
        ans += abs(va[i].se - vb[i].se);
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