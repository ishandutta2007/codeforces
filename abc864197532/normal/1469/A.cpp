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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector <bool> old(n, false);
        old[0] = true;
        for (int i = 0; i < n; ++i) {
            vector <bool> cur(n, false);
            for (int j = 0; j < n; ++j) if (old[j]) {
                if (s[i] != '(' && j - 1 >= 0) cur[j - 1] = true;
                if (s[i] != ')') cur[j + 1] = true;
            }
            swap(cur, old);
        }
        cout << (old[0] ? "YES\n" : "NO\n");
    }
}