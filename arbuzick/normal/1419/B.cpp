#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 1; (1LL << i)*((1LL << i)-1)/2 <= x; ++i)
            ans++, x -= (1LL << i)*((1LL << i)-1)/2;
        cout << ans << '\n';
    }
    return 0;
}