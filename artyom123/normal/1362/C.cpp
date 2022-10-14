#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const long long INF = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        for (int i = 0; i < 61; i++) {
            if ((1LL << i) <= n) ans += ((n - (1LL << i)) >> (i + 1)) + 1;
            if ((1LL << (i + 1)) <= n) ans += ((n - (1LL << (i + 1))) >> (i + 1)) + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}