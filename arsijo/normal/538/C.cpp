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

	int n, m;
	cin >> n >> m;

	int x, y;
	cin >> x >> y;

	int ans = x - 1 + y;
	for(int i = 1; i < m; i++){
		int a, b;
		cin >> a >> b;
		int g = abs(a - x) - abs(b - y);
		if(g < 0){
			cout << "IMPOSSIBLE";
			return 0;
		}
		ans = max(ans, g / 2 + max(b, y));
		swap(a, x);
		swap(b, y);
	}

	cout << max(ans, n - x + y);



}