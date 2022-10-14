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

void solve(int n, string &s) {
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (s[i] == '0') {
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
            return;
        }
    }
    for (int i = n / 2; i < n; i++) {
        if (s[i] == '0') {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            return;
        }
    }
    cout << 1 << " " << n / 2 << " " << 2 << " " << 1 + n / 2 << "\n";
}

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
        string s;
        cin >> s;
        solve(n, s);
    }
    return 0;
}