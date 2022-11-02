#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
bool used[maxn];
int ans[maxn];
int n;

int ask(int pos) {
    cout << "? " << pos + 1 << endl;
    int elem;
    cin >> elem;
    return elem - 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        vector<int> c;
        while (true) {
            int cur = ask(i);
            if (!c.empty() && cur == c[0]) {
                break;
            }
            c.push_back(cur);
        }
        for (int e = 0; e < (int)c.size(); e++) {
            used[c[e]] = 1;
            ans[c[e]] = c[(e + 1) % ((int)c.size())];
        }
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}

signed main() {
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}