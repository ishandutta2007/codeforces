#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
typedef long long ll;
const int MAX = 1e9;
const ld E = 1e-7;

int main() {

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;
	int l = 0, r = n - 1;
	while (s[l] == t[l])
		l++;
	while (s[r] == t[r])
		r--;
	if (l == r) {
		cout << 2;
		return 0;
	}
	int ans = 0;
	bool b = true;
	for (int i = l; i < r; i++)
		if (s[i] != t[i + 1]) {
			b = false;
			break;
		}
	if (b)
		ans++;
	b = true;
	for (int i = l; i < r; i++)
		if (s[i + 1] != t[i]) {
			b = false;
			break;
		}
	if (b)
		ans++;
	cout << ans;

}