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
        int n;
        cin >> n;
        vector<int> a(n);
        int mn = INF;
        for (auto &c : a) {
            cin >> c;
            mn = min(mn, c);
        }
        vector<int> b = a;
        sort(all(b));
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] % mn != 0) f = false;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}