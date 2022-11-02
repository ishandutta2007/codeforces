#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pii> ans;
    if (n % 2 == 1)
    {
        ans.pb(-1, 0);
        ans.pb(-2, 0);
        ans.pb(-2, -1);
        ans.pb(-2, -2);
        ans.pb(-1, -2);
        ans.pb(0, -2);
        ans.pb(0, -1);
        n--;
    }
    int len = (n / 2) * 3 + 3;
    for (int i = 0; i <= len; i++)
    {
        ans.pb(0, i);
        ans.pb(3, i);
    }
    ans.pb(1, 0);
    ans.pb(2, 0);
    ans.pb(1, len);
    ans.pb(2, len);
    int pt = 2;
    for (int i = 0; i < n / 2; i++)
    {
        ans.pb(-1, pt);
        ans.pb(-1, pt + 1);
        ans.pb(1, pt);
        ans.pb(1, pt + 1);
        pt += 3;
    }
    uniq(ans);
    cout << ans.size() << "\n";
    for (pii e : ans)
        cout << e.ff << " " << e.ss << "\n";
}