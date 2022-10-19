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

void solv()
{
    map<pair<int, int>, int> mp;
    map<int, int> mp1;
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if (x == y)
        {
            ans += mp1[x];
            mp1[x]++;
        }
        else
        {
            ans += mp1[x];
            ans += mp1[y];
            ans -= mp[m_p(x, y)];
            mp1[x]++;
            mp1[y]++;
            mp[m_p(x, y)]++;
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