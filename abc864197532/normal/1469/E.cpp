#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> pre = {0};
    for (int i = 0; i < n; ++i) pre.pb(pre.back() + (s[i] == '0'));
    set <int> has;
    int lst = min(k, 20);
    for (int i = 0; i + k <= n; ++i) {
        int val = 0;
        if (k != lst && pre[i + k - lst] - pre[i] != 0) continue;
        for (int j = i + k - lst; j < i + k; ++j) {
            val = (val << 1) | (s[j] == '0');
        }
        has.insert(val);
    }
    for (int i = 0; i < 1 << lst; ++i) if (!has.count(i)) {
        cout << "YES\n";
        cout << string(k - lst, '0');
        for (int j = lst - 1; ~j; --j) {
            if (i & (1 << j)) cout << 1;
            else cout << 0;
        }
        cout << endl;
        return;
    }
    cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}