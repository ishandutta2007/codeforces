#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i], cnt[i] = 1, ans += a[i]*a[i];
    int k3 = n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 1) {
            s.insert({a[i]*a[i]-(a[i]/2)*(a[i]/2)-(a[i]/2+a[i]%2)*(a[i]/2+a[i]%2), i});
        }
    }
    while (k3 < k) {
        ans -= s.rbegin()->f;
        int pos = s.rbegin()->s;
        cnt[pos]++;
        k3++;
        s.erase(*s.rbegin());
        if (cnt[pos] < a[pos]) {
            int k1 = (a[pos]/cnt[pos])*(a[pos]/cnt[pos])*(cnt[pos]-a[pos]%cnt[pos]);
            k1 += (a[pos]/cnt[pos]+1)*(a[pos]/cnt[pos]+1)*(a[pos]%cnt[pos]);
            int k2 = (a[pos]/(cnt[pos]+1))*(a[pos]/(cnt[pos]+1))*(cnt[pos]+1-a[pos]%(cnt[pos]+1));
            k2 += (a[pos]/(cnt[pos]+1)+1)*(a[pos]/(cnt[pos]+1)+1)*(a[pos]%(cnt[pos]+1));
            s.insert({k1-k2, pos});
        }
    }
    cout << ans << '\n';
    return 0;
}