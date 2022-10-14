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
const int mod = 1e9 + 7, abc = 864197532, N = 100007, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool is = false;
        if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') is = true;
        if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') is = true;
        if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') is = true;
        if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') is = true;
        if (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') is = true;
        cout << (is ? "YES\n" : "NO\n");
    }
}