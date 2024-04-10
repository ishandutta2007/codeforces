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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << "YES\n";
    vector <vector <bool>> is(4, vector <bool>(n, false));
    if (k & 1) {
        is[1][n >> 1] = true;
        k--;
        for (int i = (n >> 1) - 1; k && i > 0; --i) {
            is[1][i] = true;
            is[1][n - i - 1] = true;
            k -= 2;
        }
        for (int i = 1; k && i < (n >> 1); ++i) {
            is[2][i] = true;
            is[2][n - i - 1] = true;
            k -= 2;
        }
    } else {
        for (int i = 1; k && i < n - 1; ++i) {
            is[1][i] = is[2][i] = true;
            k -= 2;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
}