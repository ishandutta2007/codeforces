 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        cout << 3 * n << "\n";
        for (int i = 1; i < n; i += 2) {
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 2 << " " << i << " " << i + 1 << "\n";
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 2 << " " << i << " " << i + 1 << "\n";
            cout << 1 << " " << i << " " << i + 1 << "\n";
            cout << 2 << " " << i << " " << i + 1 << "\n";
        }
    }
    return 0;
}