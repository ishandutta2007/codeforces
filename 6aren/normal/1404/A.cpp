#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n, k;
    cin >> n >> k;;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
        bool ok1 = 0;
        bool ok0 = 0;
        for (int j = i; j < n; j += k) {
            if (s[j] == '1') ok1 = 1;
            if (s[j] == '0') ok0 = 1;
        }
        if (ok0 && ok1) {
            cout << "NO\n";
            return;
        }
        if (ok1) s[i] = '1';
        if (ok0) s[i] = '0';
    }
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 0; i < k; i++) {
        cnt1 += (s[i] == '1');
        cnt0 += (s[i] == '0');
    }
    if (cnt1 <= k / 2 && cnt0 <= k / 2) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}