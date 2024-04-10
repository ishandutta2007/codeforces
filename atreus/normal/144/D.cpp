#include <iostream>
#include <deque>
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
const int inf = 1e9 + 7, maxn = 1e5 + 100;
int ans, n, m, src, len, dp[maxn], wei[maxn];
vector <pair <int, int> > v[maxn];
pair <int, int> edg[maxn];
set <pair <int, int> > s;

void dijsktra (int src){
	memset (dp, 63, sizeof dp);
	dp[src] = 0;
	for (int i = 1; i <= n; i++)
		s.In(MP(dp[i], i));
	while (!s.empty()){
		int u = (*s.begin()).S;
		ans += (dp[u] == len);
		s.erase (s.begin());
		for (auto w : v[u]){
			if (dp[w.F] > dp[u] + w.S){
				s.erase (MP(dp[w.F], w.F));
				dp[w.F] = dp[u] + w.S;
				s.insert (MP(dp[w.F], w.F));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> src;
	for (int i = 0; i < m; i++){
		int u1, u2, w;
		cin >> u1 >> u2 >> w;
		v[u1].PB(MP(u2, w));
		v[u2].PB(MP(u1, w));
		edg[i] = MP(u1, u2);
		wei[i] = w;
	}
	cin >> len;
	dijsktra (src);
	for (int i = 0; i < m; i++){
		int u = edg[i].F, w = edg[i].S;
		int a = dp[u], b = dp[w];
		if (a < b)
			swap (a, b);
		if (a >= len and b < len and b + wei[i] > len){
			ans ++;
			continue;
		}
		if (a < len and b < len){
			if (2 * len - a - b < wei[i]){
				ans += 2;
			}
			else if (2 * len - a - b == wei[i])
				ans ++;
			else
				continue;
		}
	}
	cout << ans << endl;
}