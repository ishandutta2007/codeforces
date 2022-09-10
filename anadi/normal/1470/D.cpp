#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
vector <int> G[N];
set <int> all, can;

void solve() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		G[i].clear();
	
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	all.clear();
	for(int i = 2; i <= n; ++i)
		all.insert(i);
	
	can.clear();
	can.insert(1);
	
	vector <int> ans;
	while(can.size() > 0) {
		auto u = *can.begin();
		can.erase(can.begin());
		
		ans.push_back(u);
		vector <int> cur;

		for(auto v: G[u]) {
			if(all.count(v)) {
				all.erase(v);
				cur.push_back(v);
			}
			else if(can.count(v)) {
				can.erase(v);
				cur.push_back(v);
			}
		}
		
		for(auto v: cur)
			for(auto t: G[v])
				if(all.count(t)) {
					all.erase(t);
					can.insert(t);
				}
	}
	
	if(all.size() > 0) {
		puts("NO");
		return;
	}
	
	puts("YES");
	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d ", v);
	puts("");
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}