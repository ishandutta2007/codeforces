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
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        for (int i = 0; i < 62; i++) {
            if (a * (1LL << i) == b) {
                cout << (i + 2) / 3 << "\n";
                break;
            }
            if (i == 61) cout << -1 << "\n";
        }
    }
    return 0;
}