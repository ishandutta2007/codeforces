#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e6 + 100;
const int inf = (int)1e9;

vector <int> v[maxn];
int a[maxn];

int ted[maxn][2];

ll ans;

void dfs (int u, int bit, int par = -1) {
	bool p = (a[u] >> bit) & 1;
	ted[u][p] = 0;
	ted[u][1 - p] = 0;
	for (auto w : v[u]) {
		if (w != par) {
			dfs (w, bit, u);
			ted[u][0] += ted[w][0];
			ted[u][1] += ted[w][1];
		}
	}
	
	if (p) {
		ll tmp = 0;
		for (auto w : v[u]) {
			if (w != par) {
				tmp += (1ll << bit) * ted[w][0] * (ted[u][0] - ted[w][0]);
				tmp += (1ll << bit) * ted[w][1] * (ted[u][1] - ted[w][1]);
			}
		}
		ans += tmp / 2;
		ans += (ted[u][0] + 1) * (1ll << bit);
		tmp = ted[u][0];
		ted[u][0] = ted[u][1];
		ted[u][1] = tmp + 1;
	}
	else {
		ll tmp = 0;
		for (auto w : v[u]) {
			if (w != par) {
				tmp += (1ll << bit) * ted[w][0] * (ted[u][1] - ted[w][1]);
				tmp += (1ll << bit) * ted[w][1] * (ted[u][0] - ted[w][0]);
			}
		}
		ans += tmp / 2;
		ans += ted[u][1] * (1ll << bit);
		ted[u][0] ++;
	}
}

int main(){ 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	for (int i = 0; i < 20; i++) {
		dfs (1, i);
	}
	cout << ans << endl;
}