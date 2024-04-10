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
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 0) cnt0++;
            else cnt1++;
        }
        if (cnt1 <= n / 2) {
            cout << cnt0 << "\n";
            for (int i = 0; i < cnt0; i++) cout << 0 << " ";
            cout << "\n";
        } else {
            if (cnt1 % 2 == 1) cnt1--;
            cout << cnt1 << "\n";
            for (int i = 0; i < cnt1; i++) cout << 1 << " ";
            cout << "\n";
        }
    }
    return 0;
}