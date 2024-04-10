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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

set <lli> s;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, pw = 1, cnt = 0;
    while (cnt < 11) {
        for (int i = 1; i < 10; ++i) {
            s.insert(pw * i);
        }
        pw *= 10;
        cnt++;
    }
    cin >> n;
    cout << *s.upper_bound(n) - n << endl;
}