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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(rall(a));
    int ans = 0;
    multiset<int> s;
    for (int i = 0; i < k+1; ++i)
        s.insert(0);
    for (int i = 0; i < n; ++i) {
        int c = *s.rbegin();
        s.erase(s.find(c));
        ans += c;
        c += a[i];
        s.insert(c);
    }
    cout << ans;
    return 0;
}