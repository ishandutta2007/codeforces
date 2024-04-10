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

int n, k;
vector<int> l, r;

void solv()
{
    cin >> n >> k;
    l.clear();
    r.clear();
    while (n--)
    {
        int x;
        cin >> x;
        if (x > 0)
            r.push_back(x);
        else if (x < 0)
            l.push_back(-x);
    }
    l.push_back(0);
    r.push_back(0);
    sort(all(r));
    sort(all(l));

    ll ans = 0;
    for (int i = sz(r) - 1; i >= 0; i -= k)
        ans += 2 * r[i];
    for (int i = sz(l) - 1; i >= 0; i -= k)
        ans += 2 * l[i];

    ans -= max(r.back(), l.back());

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