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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pii> block;
    map <int, int> m1;
    for (int i = 0, r, c; i < m; ++i) {
        cin >> r >> c, r--, c--;
        block.eb(c, r);
        m1[c]++;
    }
    block.eb(n, 0);
    block.eb(n, 1);
    sort(all(block));
    bool is = true;
    int lst0 = -1, lst1 = -1;
    for (int i = 0, r, c; i < m + 2; ++i) {
        tie(c, r) = block[i];
        if (r) {
            if (~lst1) {
                is &= ((c - lst1) % 2 == 1);
                if (lst1 != c) {
                    is &= m1[lst1] == 1;
                    is &= m1[c] == 1;
                }
                lst1 = -1;
            } else if (~lst0) {
                is &= ((c - lst0) % 2 == 0);
                if (lst0 != c) {
                    is &= m1[lst0] == 1;
                    is &= m1[c] == 1;
                }
                lst0 = -1;
            } else {
                lst1 = c;
            }
        } else {
            if (~lst1) {
                is &= ((c - lst1) % 2 == 0);
                if (lst1 != c) {
                    is &= m1[lst1] == 1;
                    is &= m1[c] == 1;
                }
                lst1 = -1;
            } else if (~lst0) {
                is &= ((c - lst0) % 2 == 1);
                if (lst0 != c) {
                    is &= m1[lst0] == 1;
                    is &= m1[c] == 1;
                }
                lst0 = -1;
            } else {
                lst0 = c;
            }
        }
    }
    is &= (lst0 == -1 && lst1 == -1);
    cout << (is ? "YES\n" : "NO\n");
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