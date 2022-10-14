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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    lli k;
    cin >> n >> m >> k;
    k++;
    if (k <= n) {
        cout << k << ' ' << 1 << endl;
    } else {
        k -= n + 1;
        m--;
        lli row = k / (m * 2), col = k % (m * 2);
        if (col < m) {
            cout << n - row * 2 << ' ' << col + 2 << endl;
        } else {
            cout << n - row * 2 - 1 << ' ' << m * 2 + 1 - col << endl;
        }
    }
}