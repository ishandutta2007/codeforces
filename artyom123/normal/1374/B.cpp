#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt3 = 0;
        while (n % 3 == 0) {
            n /= 3;
            cnt3++;
        }
        int cnt2 = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt2++;
        }
        if (n != 1 || cnt2 > cnt3) cout << -1 << "\n";
        else cout << cnt3 + cnt3 - cnt2 << "\n";
    }
    return 0;
}