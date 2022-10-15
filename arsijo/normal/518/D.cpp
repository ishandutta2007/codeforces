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
typedef pair<int, int> ii;
typedef set<ii>::iterator iter;
typedef multiset<int>::iterator miter;
const int MAX = 1e9;
const ld E = 1e-7;

int main() {

	int n, t;
	ld p;
	cin >> n >> p >> t;

	ld ar[t + 1][n + 1];
	ms(ar);

	ar[0][0] = 1;
	for(int i = 1; i <= t; i++){

		for(int j = 0; j < n; j++){
			ar[i][j] += ar[i - 1][j] * (1 - p);
			ar[i][j + 1] += ar[i - 1][j] * p;
		}

		ar[i][n] += ar[i - 1][n];

	}

	ld ans = 0;
	for(int i = 0; i <= n; i++)
		ans += ar[t][i] * i;

	cout.precision(8);
	cout << fixed << ans << endl;


}