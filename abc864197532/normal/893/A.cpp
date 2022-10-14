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
const int mod = 1e9 + 7, abc = 864197532, N = 800007, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a = 1, b = 2, c = 3;
    cin >> n;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        if (c == tmp) {
            cout << "NO\n";
            return 0;
        }
        if (b == tmp) swap(a, c);
        else swap(b, c);
    }
    cout << "YES\n";
}