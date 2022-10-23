#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll sum0 = 0;
        map<ll, ll> cnt;
        for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++, sum0 += x;
        ll sum1 = sum0 + 1;
        ll cnt0 = 1, cnt1 = 0;
        bool check = true;
        while (sum0 >= 1 && cnt0 + cnt1 > 0)
        {
            if (cnt.count(sum0))
            {
                int mn = min(cnt[sum0], cnt0);
                cnt0 -= mn;
                cnt[sum0] -= mn;
            }
            if (cnt.count(sum1))
            {
                int mn = min(cnt[sum1], cnt1);
                cnt1 -= mn;
                cnt[sum1] -= mn;
            }
            if (sum0 & 1)
                cnt1 = cnt1 * 2 + cnt0;
            else
                cnt0 = cnt0 * 2 + cnt1;
            sum0 /= 2;
            sum1 = sum0 + 1;
        }
        if (cnt.count(1))
        {
            cnt1 -= min(cnt[1], cnt1);
        }
        if (cnt1) check = false;
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}