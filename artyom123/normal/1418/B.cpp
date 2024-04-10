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
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> l(n), b;
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (l[i] == 0) b.pb(a[i]);
        }
        sort(all(b));
        for (int i = 0; i < n; i++) {
            if (l[i]) cout << a[i] << " ";
            else {
                cout << b.back() << " ";
                b.pop_back();
            }
        }
        cout << "\n";
    }
    return 0;
}