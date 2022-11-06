#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while(n) {
        ans += n%k;
        n -= n%k;
        if(n) {
            ans++;
            n /= k;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;

    cin >> t;
    while(t--)
        cout << f() << '\n';
    return 0;
}