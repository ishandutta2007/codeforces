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
        int n, m;
        cin >> n >> m;
        m = min(m, n);
        string s;
        cin >> s;
        for (int it = 0; it < m; it++) {
            vector<int> id;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') continue;
                int cnt = 0;
                if (i > 0 && s[i - 1] == '1') cnt++;
                if (i + 1 < n && s[i + 1] == '1') cnt++;
                if (cnt == 1) id.pb(i);
            }
            for (auto &c : id) s[c] = '1';
        }
        cout << s << "\n";
    }
    return 0;
}