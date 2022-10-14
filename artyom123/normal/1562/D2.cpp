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

vector<vector<int>> solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pr(n + 1);
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (s[i] == '+') x = 1;
        else x = -1;
        if (i % 2 == 1) x *= -1;
        pr[i + 1] = pr[i] + x;
    }
    map<int, vector<int>> ma;
    for (int i = 0; i < n; i++) ma[pr[i] + pr[i + 1]].pb(i);
    vector<vector<int>> ans;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (pr[r + 1] - pr[l] == 0) {
            ans.pb(vector<int>(0));
            continue;
        }
        vector<int> now;
        if ((r - l + 1) % 2 == 0) {
            now.pb(l);
            l++;
        }
        now.pb(*lower_bound(all(ma[pr[l] + pr[r + 1]]), l));
        ans.pb(now);
    }
    return ans;
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
        for (auto &c : solve()) {
            cout << c.size() << "\n";
            for (auto &l : c) cout << l + 1 << " ";
            cout << "\n";
        }
    }
    return 0;
}