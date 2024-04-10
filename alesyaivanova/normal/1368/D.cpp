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

//const int maxn = 2e5 + 9;
//int a[maxn];
int n;
int lg = 22;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> cnt(lg, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int e = 0; e < lg; e++)
        {
            if (a % 2)
                cnt[e]++;
            a /= 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int e = lg - 1; e >= 0; e--)
        {
            cur *= 2;
            if (cnt[e])
            {
                cur++;
                cnt[e]--;
            }
        }
        ans += cur * cur;
    }
    cout << ans;
}