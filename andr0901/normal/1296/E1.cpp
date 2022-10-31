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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    string needed = s;
    sort(all(needed));
    vector <int> ans(n, -1);
    vector <pii> swaps;
    forn (i, 0, n) {
        int idx;
        forn (j, i, n) {
            if (s[j] == needed[i]) {
                idx = j;
                break;
            }
        }
        if (ans[i] == -1)
            ans[i] = 0;
        if (idx == i)
            continue;
        forn (j, i + 1, idx) {
            if (ans[i] != -1 && ans[j - 1] != ans[i]) {
                cout << "NO\n";
                return 0;
            }
            ans[j] = ans[j - 1];
        }
        if (ans[idx] != -1 && ans[idx] != (ans[idx - 1] ^ 1)) {
            cout << "NO\n";
            return 0;
        }
        ans[idx] = ans[idx - 1] ^ 1;
        for (int j = idx; j > i; j--) {
            swap(ans[j], ans[j - 1]);
            swap(s[j], s[j - 1]);
            swaps.eb(j, j - 1);
        }
        /*cout << i << " " << idx << ": ";
        for (int j : ans)
            cout << j;
        cout << "\n";*/
    }
    while (!swaps.empty()) {
        swap(ans[swaps.back().fs], ans[swaps.back().sc]);
        swaps.pop_b();
    }
    cout << "YES\n";
    for (int i : ans)
        cout << i;
    return 0;
}