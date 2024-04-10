#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pp;
int main() {
    int n;
    cin >> n;
    pp a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    sort(a, a + n);
    map<ll, ll> r;
    pi ans(0, 0);
    for (pp i : a) {
        while (!r.empty() && ans.first <= i.first) {
            ll tmp = r.begin()->first;
            if (r[tmp] < i.first) {
                if (r[tmp] >= ans.first + tmp) {
                    ll x = (r[tmp] - ans.first) / tmp;
                    ans.second += x;
                    ans.first += tmp * x;
                }
                r.erase(tmp);
                continue;
            }
            ll x = min((i.first - ans.first) / tmp + 1, (r[tmp] - ans.first) / tmp);
            ans.second += x;
            ans.first += x * tmp;
            if (ans.first <= i.first) r.erase(tmp);
        }
        if (r.empty()) ans.first = max(ans.first, i.first);
        r[i.second.second] = max(r[i.second.second], i.second.first);
        if (i.first + i.second.second < ans.first)
            ans.first = i.first + i.second.second;
    }
    while (!r.empty()) {
        ll tmp = r.begin()->first;
        if (r[tmp] >= ans.first + tmp) {
            ll x = (r[tmp] - ans.first) / tmp;
            ans.second += x;
            ans.first += tmp * x;
        }
        r.erase(tmp);
    }
    cout << ans.second;
}