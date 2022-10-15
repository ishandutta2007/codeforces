#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1000;
#else
const int MAX = 2e5 + 1;
#endif

struct dsu {
	int *ar, n;
	dsu(int n) {
		this->n = n;
		ar = new int[n];
		for (int i = 0; i < n; i++)
			ar[i] = i;
	}
	int get(int pos) {
		return (ar[pos] == pos ? pos : ar[pos] = get(ar[pos]));
	}
	void unite(int a, int b) {
		if (get(a) != get(b))
			ar[get(a)] = get(b);
	}
};

bool ar[1000][1000], used[1000][1000];
int n, m, X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
int ans[1000000];

void dfs(int x, int y, int v, dsu d){
	used[x][y] = true;
	//cout << "go " << x << " " << y << endl;
	d.unite( x * m + y, v);
	for(int i = 0; i < 4; i++){
		int x1 = x + X[i];
		int y1 = y + Y[i];
		if(!ar[x1][y1]){
			//cout << "add " << x << " " << y << " " << x1 << " " << y1 << " " << v << endl;
			ans[v]++;
		}
		else if(!used[x1][y1])
			dfs(x1, y1, v, d);
	}
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int k;
	cin >> n >> m >> k;

	ms(ar, 0);
	ms(used, 0);
	ms(ans, 0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			ar[i][j] = c == '.';
		}
	}

	dsu d(n * m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!used[i][j] && ar[i][j] && ans[d.get(i * m + j)] == 0){
				//cout << "start " << i << " " << j << " " << d.get(i * m + j) << endl;
				dfs(i, j, d.get(i * m + j), d);
			}
		}
	}

	while(k--){
		int x, y;
		cin >> x >> y;
		int pos = d.get((x - 1) * m + (y - 1));
		//cout << pos << " " << (x - 1) * m + (y - 1) << endl;
		cout << ans[pos] << endl;
	}

}