#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
const int MAX = 1e9;
const ld E = 1e-11;
typedef pair<int, int> ii;

int main() {

	sync;
	int n;
	cin >> n;

	int ar[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> ar[i][j];

	bool ans = true;

	for(int i = 0; i < n && ans; i++)
		for(int j = 0; j < n && ans; j++)
			if(ar[i][j] != ar[j][i] || (i != j && ar[i][j] == 0))
				ans = false;

	for(int i = 0; i < n && ans; i++)
		if(ar[i][i] != 0)
			ans = false;

	for(int i = 0; i < n && ans; i++){
		int g = (i + 1) % n;
		for(int j = 0; j < n; j++)
			if(ar[i][j] < ar[i][g] && i != j)
				g = j;
		for(int a = 0; a < n; a++)
			if(abs(ar[a][i] - ar[a][g]) != ar[i][g])
				ans = false;
	}

	cout << (ans ? "YES" : "NO");

}