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
const int inf = 1e9 + 7, maxn = 2e5 + 500;
set <pair <ll, int> > s;
vector <pair <int, ll> > v[maxn];
ll n, a[maxn], dp[maxn];

void dijkstra(){
	for (int i = 1; i <= n; i++)
		s.insert (MP(dp[i], i));
	while (!s.empty()){
		ll u = (*s.begin()).S;
		s.erase(s.begin());
		for (auto w : v[u]){
			if (dp[w.F] > dp[u] + 2 * w.S){
				s.erase (MP(dp[w.F], w.F));
				dp[w.F] = dp[u] + 2 * w.S;
				s.insert (MP(dp[w.F], w.F));
			}
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		ll u, w, c;
		cin >> u >> w >> c;
		v[u].PB(MP(w, c));
		v[w].PB(MP(u, c));
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
}