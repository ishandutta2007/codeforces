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
    int n, m;
    cin >> n >> m;
    lli g = 0, tmp;
    vector <lli> a(n);
    for (lli &i : a) cin >> i;
    sort(all(a));
    for (int i = 1; i < n; ++i) g = __gcd(g, a[i] - a[0]);
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        cout << __gcd(g, tmp + a[0]) << ' ';
    }
}