#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 3e5 + 500;
ll mark[maxn], dp[maxn], par[maxn], n;
vector <pair <pair <int, int>, int> > v[maxn];
vector <int> ans;

void dijkstra(int st){
	memset (dp, 63, sizeof dp);
	dp[st] = 0;
	set <pair <ll, int> > s;
	for (int i = 1; i <= n; i++)
		s.insert(MP(dp[i], i));

	for (int _ = 1; !s.empty() and _ <= n; _ ++){
		int u = (*s.begin()).S;
		s.erase(s.begin());
		if (_ > 1)
			ans.PB(par[u]);
		for (auto w : v[u]){
			if (dp[w.F.F] > dp[u] + w.F.S){
				s.erase(MP(dp[w.F.F], w.F.F));
				par[w.F.F] = w.S;
				dp[w.F.F] = dp[u] + w.F.S;
				s.insert(MP(dp[w.F.F], w.F.F));
			}
			else if (dp[w.F.F] == dp[u] + w.F.S)
				par[w.F.F] = w.S;
		}
	}
}

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	int m, st;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, w, l;
		cin >> u >> w >> l;
		mark[i] = l;
		v[u].PB(MP(MP(w, l), i));
		v[w].PB(MP(MP(u, l), i));
	}
	cin >> st;
	dijkstra (st);
	ll cnt = 0;
	for (int i = 0; i < ans.size(); i++){
		int k = ans[i];
		cnt += mark[k];
	}
	cout << cnt << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}