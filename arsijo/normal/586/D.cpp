#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

bool solve() {
	int n, m;
	cin >> m >> n;
	n = 3;
	char ar[n][m * 3 + 2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];
		for(int j = m; j < m * 3 + 2; j++)
			ar[i][j] = '.';
	}
	bool bol[n][m * 3 + 2 + 1];
	ms(bol, 0);
	for(int i = 0; i < 3; i++)
		if(ar[i][0] == 's')
			bol[i][0] = true;
	int pos = 0;
	for(int i = 1; i <= m; i++){
		bool b[3];
		pos++;
		for(int j = 0; j < 3; j++){
			dbg << pos << " " << ar[j][pos] << " " << ar[j][pos + 2] << endl;
			b[j] = ar[j][pos] == '.' && ar[j][pos + 2] == '.';
		}
		bol[0][i] = b[0] && ((bol[0][i - 1] && ar[0][pos] == '.') || (bol[1][i - 1] && ar[1][pos] == '.'));
		bol[1][i] = b[1] && ((bol[0][i - 1] && ar[0][pos] == '.') || (bol[1][i - 1] && ar[1][pos] == '.') || (bol[2][i - 1] && ar[2][pos] == '.'));
		bol[2][i] = b[2] && ((bol[1][i - 1] && ar[1][pos] == '.') || (bol[2][i - 1] && ar[2][pos] == '.'));
		dbg << pos << " " << bol[0][i] << " " << bol[1][i] << " " << bol[2][i] << " " << b[0] << " " << b[1] << " " << b[2] << endl;
		pos += 2;
	}
	return bol[0][m] || bol[1][m] || bol[2][m];
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int t;
	cin >> t;
	while(t--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}

}