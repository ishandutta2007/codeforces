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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

int ask(int n) {
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) return 366;
    return 365;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << (n + k) / k * k << endl;
}