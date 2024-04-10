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
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    map <int, int> m1;
    m1[0] = -1;
    int ans = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        pre += s[i] == '0' ? -1 : 1;
        if (m1.count(pre)) ans = max(ans, i - m1[pre]);
        else m1[pre] = i;
    }
    cout << ans;
}