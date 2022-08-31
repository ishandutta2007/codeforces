#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define INF 10000000000000
#define MOD 1000000007

int n;
vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> n;
	g = std::vector<std::vector<int> >(n, std::vector<int>());
	gr = std::vector<std::vector<int> >(n, std::vector<int>());
	
	int cost[n];
	for(int i = 0; i < n; i++) {
		std::cin >> cost[i];
	}
	
	int m;
	std::cin >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
        gr[b].push_back(a);
	}
		
	used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
            
    used.assign (n, false);
    
    
    
    int ans = 0;
    int count = 1;
    
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            
            int min = INF;
            int num = 0;
            
            for(int j : component) {
            	if(cost[j] < min) {
            		min = cost[j];
            		num = 1;
            	}
            	else if(cost[j] == min)
            		num++;
            }
            
            ans += min;
            count *= num;
            count %= MOD;
            
            component.clear();
        }
    }
	
	std::cout << ans << " " << count << std::endl;
	
	return 0;
}