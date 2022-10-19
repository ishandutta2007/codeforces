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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b*c) {
            cout << -1 << '\n';
            continue;
        }
        int x = (a-1)/(d*b)+1;
        int ans = x*a;
        ans = ans-((1+x-1)*(x-1)/2)*d*b;
        cout << ans << '\n';
    }
    return 0;
}