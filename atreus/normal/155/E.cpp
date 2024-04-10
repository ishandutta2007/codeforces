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

unordered_map <ll, int> mp;

vector <int> v[maxn];

ll base = 15485867;

ll H[maxn], arz[maxn];

ll hsh (int id) {
	ll tmp = 1, ret = 0;
	for (auto w : v[id]) {
		ret += arz[w];
	}
	return ret;
}

pii ed[maxn];

int main(){ 
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	arz[0] = 1;
	for (int i = 1; i <= n; i++)
		arz[i] = arz[i - 1] * base;
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
		ed[i] = {u, w};
	}
	for (int i = 1; i <= n; i++)
		sort (v[i].begin(), v[i].end());
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		H[i] = hsh (i);
		ll k = H[i];
		ans += mp[k];
		mp[k] ++;
	}
	
	for (int i = 1; i <= m; i++) {
		if (H[ed[i].F] - arz[ed[i].S] == H[ed[i].S] - arz[ed[i].F])
			ans ++;
	}

	cout << ans << endl;
}