#include<bits/stdc++.h>

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
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> b(n);
        for (auto &c : b) cin >> c;
        if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
            cout << "No\n";
            continue;
        }
        vector<pair<int, int>> lol;
        vector<pair<int, int>> kek;
        for (int i = 0; i < (n + 1) / 2; i++) lol.pb(min(a[i], a[n - 1 - i]), max(a[i], a[n - 1 - i]));
        for (int i = 0; i < (n + 1) / 2; i++) kek.pb(min(b[i], b[n - 1 - i]), max(b[i], b[n - 1 - i]));
        sort(all(lol));
        sort(all(kek));
        cout << (lol == kek ? "Yes\n" : "No\n");
    }
    return 0;
}