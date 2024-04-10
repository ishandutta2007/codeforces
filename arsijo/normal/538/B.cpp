#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
const int MAX = 1e9;
const ld E = 1e-7;

int main() {

	int ar[9];
	ms(ar);
	int ans = 0;
	int a;
	cin >> a;
	int e = 1;
	while (a != 0) {
		int g = a % 10;
		ans = max(ans, g);
		if (g != 0)
			for (int i = 0; i < g; i++)
				ar[i] = ar[i] + e;
		e *= 10;
		a /= 10;
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++)
		cout << ar[i] << " ";
}