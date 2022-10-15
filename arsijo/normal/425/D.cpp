#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	vector<int> x[MAX], y[MAX];

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
		y[b].push_back(a);
	}

	for(int i = 0; i < MAX; i++) {
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
	}

	int ans = 0;

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < (int) x[i].size(); j++) {
			int px = i, py = x[i][j];
			ui tx = j + 1, ty = distance(y[py].begin(),
					upper_bound(y[py].begin(), y[py].end(), px));
			while(tx < x[px].size() && ty < y[py].size()){
				int lx = y[py][ty] - px;
				int ly = x[px][tx] - py;
				if(lx < ly){
					ty++;
					continue;
				}
				if(ly < lx){
					tx++;
					continue;
				}
				if(binary_search(x[y[py][ty]].begin(), x[y[py][ty]].end(), x[px][tx]))
					ans++;
				tx++, ty++;
			}
		}
	}

	cout << ans;

}