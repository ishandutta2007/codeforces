#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && a[i] < 0) a[i] *= -1;
            if (i % 2 == 1 && a[i] > 0) a[i] *= -1;
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}