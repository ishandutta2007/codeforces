#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    map <pii, int> last;
    pii cur = {0, 0};
    last[cur] = -1;
    int ans_i, ans_j;
    int ans = 1e9;
    forn (i, 0, n) {
        char c;
        cin >> c;
        if (c == 'L')
            cur.fs--;
        if (c == 'R')
            cur.fs++;
        if (c == 'U')
            cur.sc++;
        if (c == 'D')
            cur.sc--;
        if (last.find(cur) != last.end()) {
            if (i - last[cur] < ans) {
                ans_i = last[cur], ans_j = i;
            }
            ans = min(ans, i - last[cur]);
        }
        last[cur] = max(last[cur], i);
    }
    if (ans > n) {
        cout << "-1\n";
        return;
    }
    //cout << ans << "\n";
    cout << ans_i + 2 << " " << ans_j + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}