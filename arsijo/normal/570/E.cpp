#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<ii>::iterator vit;
typedef double ld;
typedef int** matrix;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 101;
///#define DEBUG
#else
const ll MAX = 5e5 + 5;
#endif

int X[4] = { -1, 0, 1, 0 }, Y[4] = { 0, -1, 0, 1 };

struct str {

	int n, m, **a, **b;

	int** create() {
		int **c = new int*[n];
		for (int i = 0; i < n; i++) {
			c[i] = new int[n];
			for (int j = 0; j < n; j++)
				c[i][j] = 0;
		}
		return c;
	}

	str(int n, int m) {
		this->n = n;
		this->m = m;
		a = create();
		b = create();
	}

	int get(int a, int b, int c, int d) {
		return this->a[a][c];
	}

	void add(int a, int b, int c, int d, int val) {
		this->b[a][c] = (this->b[a][c] + val)mod;
	}

	void next(){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				a[i][j] = b[i][j];
				b[i][j] = 0;
			}
	}

};

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	char ar[n][m];
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	cin >> ar[i][j];

	str st(n, m);

	st.add(0, 0, n - 1, m - 1, ar[0][0] == ar[n - 1][m - 1]);
	st.next();
	for(int q = 1; q <= (n + m - 2) / 2; q++) {
		vector<ii> v1, v2;
		for(int i = 0; i < n + m; i++) {
			int j = q - i;
			if(0 <= i && i < n && 0 <= j && j < m) {
				v1.push_back(make_pair(i, j));
				v2.push_back(make_pair(n - i - 1, m - j - 1));
			}
		}
		for(int i = 0; i < (int) v1.size(); i++)
		for(int j = 0; j < (int) v2.size(); j++)
		if(ar[v1[i].first][v1[i].second] == ar[v2[j].first][v2[j].second]) {

			for(int a = 0; a < 2; a++)
			for(int b = 2; b < 4; b++) {
				int x1 = v1[i].first + X[a], y1 = v1[i].second + Y[a];
				int x2 = v2[j].first + X[b], y2 = v2[j].second + Y[b];
				if(0 <= x1 && 0 <= x2 && x1 < n && x2 < n && 0 <= y1 && 0 <= y2 && y1 < m && y2 < m) {
					st.add(v1[i].first, v1[i].second, v2[j].first, v2[j].second, st.get(x1, y1, x2, y2));
				}
			}
		}
		st.next();
	}

	ll ans = 0;

	if( (n + m) % 2 == 0 ) {
		int q = (n + m - 2) / 2;
		for(int i = 0; i < n + m; i++) {
			int j = q - i;
			if(0 <= i && i < n && 0 <= j && j < m)
			ans = (ans + st.get(i, j, i, j)) mod;
		}
	} else {
		int q = (n + m - 2) / 2;
		for(int i = 0; i < n + m; i++) {
			int j = q - i;
			if(0 <= i && i < n && 0 <= j && j < m) {
				for(int a = 2; a < 4; a++) {
					int x = i + X[a], y = j + Y[a];
					if(0 <= x && x < n && 0 <= y && y < m && ar[i][j] == ar[x][y])
					ans = (ans + st.get(i, j, x, y)) mod;
				}
			}
		}
	}

	cout << ans;

}