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
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        for (int k = 1; k <= 2000; k++) {
            set<int> now;
            for (auto &c : s) now.insert(c ^ k);
            if (now == s) {
                cout << k << "\n";
                break;
            }
            if (k == 2000) {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}