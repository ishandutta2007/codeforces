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

int X[4] = { 1, 0, -1, 0 }, Y[4] = { 0, 1, 0, -1 };

int main() {

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << ((x1 <= x2 && y1 <= y2) || (x1 + y1 <= max(x2, y2)) ?
					"Polycarp" : "Vasiliy");

}