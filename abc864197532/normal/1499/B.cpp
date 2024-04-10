#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) {\
    for (auto a : x) cout << a << ' ';\
    cout << endl;\
}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 20000087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        bool is = false, ans = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1' && s[i - 1] == '1') is = true;
            if (is && s[i - 1] == '0' && s[i] == '0') {
                ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}