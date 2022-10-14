#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ld long double
#define pb emplace_back
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        for (int i = 0; i < n / 2; i++) {
            cout << -a[n - 1 - i] << " ";
        }
        for (int i = n / 2; i < n; i++) {
            cout << a[n - 1 - i] << " ";
        }
        cout << "\n";
    }
    return 0;
}