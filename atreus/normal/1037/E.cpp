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
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 1e9;
const int block = 400;

int n, m, k;

int dp[maxn], st[maxn], a[maxn];

bool visited[maxn];
vector <int> v[maxn];

int ans;

void find_array () {
	set <pii> s;
	for (int i = 1; i <= n; i++) {
		dp[i] = v[i].size();
		s.insert ({dp[i], i});
	}
	int Mytime = 1;
	while (!s.empty()) {
		auto it = *s.begin();
		s.erase (s.begin());
		int u = it.S;
		visited[u] = 1;
		if (dp[u] < k) {
			for (auto w : v[u]) {
				if (!visited[w]) {
					s.erase ({dp[w], w});
					dp[w] --;
					s.insert ({dp[w], w});
				}
			}
		}
		else {
			ans ++;
		}
	}
}


set <pii> s;

void dfs (int u) {
	if (dp[u] == k - 1) {
		for (auto w : v[u]) {
			if (dp[w] >= k) {
				dp[w] --;
				if (dp[w] == k - 1)
					dfs (w);
			}
		}
		s.erase ({k - 1, u});
		ans --;
	}
}

pii ed[maxn];

int main () { 
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> ed[i].F >> ed[i].S;
		v[ed[i].F].PB (ed[i].S);
		v[ed[i].S].PB (ed[i].F);
	}

	find_array();

	for (int i = 1; i <= n; i++) {
		s.insert ({dp[i], i});
	}
	
	int tmp = 0;
	a[tmp ++] = ans;
	for (int i = m; i > 1; i--) {
		int u = ed[i].F, w = ed[i].S;
		if (MP (dp[u], u) > MP (dp[w], w))
			swap (u, w);
		
		dp[u] --;
		if (dp[u] >= k)
			dp[w] --;
		dfs (u);
		v[u].pop_back();
		v[w].pop_back();
		a[tmp ++] = ans;
	}
	for (int i = tmp - 1; i >= 0; i--)
		cout << a[i] << '\n';
}