#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = INF;
        int n1 = n;
        n1 += max(0, k - n1);
        n1 += (n1 - k) % 2;
        ans = n1 - n;
        ans = min(ans, abs(k - n));
        cout << ans << "\n";
    }
    return 0;
}