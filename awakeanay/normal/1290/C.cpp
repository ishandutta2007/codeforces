#include <iostream>
#include <vector>

#define MAX 400000

int ans;
int par[MAX];
int enemy[MAX];
int choice[MAX];

int count(int u) {
	int v = enemy[u];
	if(choice[u] > 0 || (v != -1 && choice[v] < 0))
		return -par[u];
	if(v == -1)
		return 0;
	if(choice[u] == 0 && choice[v] == 0)
		return -std::max(par[u], par[v]);
	return -par[v];
}

int root(int u) {
	if(par[u] < 0)
		return u;
	return par[u] = root(par[u]);
}

int merge(int u, int v) {
	u = root(u);
	v = root(v);
	
	if(u == v)
		return u;
		
	ans -= count(u);
	ans -= count(v);
	
	if(par[u] < par[v])
		u ^= v ^= u ^= v;
	
	par[v] += par[u];
	par[u] = v;
	choice[v] += choice[u];
	
	int x, y;
	
	if(enemy[v] == -1) {
		enemy[v] = enemy[u];
		enemy[enemy[u]] = v;
	}
	else if(enemy[u] != -1) {
		x = enemy[u];
		y = enemy[v];
		
		if(par[x] < par[y])
			x ^= y ^= x ^= y;
	
		par[y] += par[x];
		par[x] = y;
		choice[y] += choice[x];
		
		enemy[v] = y;
		enemy[y] = v;
	}
	
	ans += count(v);
	return v;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	
	std::string b;
	std::cin >> b;
	
	std::vector<int> con[n];
	
	for(int i = 0; i < k; i++) {
		int c;
		std::cin >> c;
		
		par[i] = -1;
		enemy[i] = -1;
		choice[i] = 0;
		
		for(int j = 0; j < c; j++) {
			int x;
			std::cin >> x;
			x--;
			con[x].push_back(i);
		}
	}
	
	for(int i = 0; i < b.length(); i++) {
		//std::cout << "size: " << con[i].size() << std::endl;
		if(b[i] == '1') {
			if(con[i].size() == 1) {
				int x = root(con[i][0]);
				ans -= count(x);
				choice[x] = -1;
				ans += count(x);
			} else if(con[i].size() == 2) {
				merge(root(con[i][0]), root(con[i][1]));
			}
		} else {
			if(con[i].size() == 1) {
				int x = root(con[i][0]);
				ans -= count(x);
				choice[x] = 1;
				ans += count(x);
			} else if(con[i].size() == 2) {
				int x = root(con[i][0]);
				int y = root(con[i][1]);
				
				//std::cout << x << " " << y << std::endl;
				
				if(enemy[x] == -1 && enemy[y] == -1) {
					ans -= count(x) + count(y);
					enemy[x] = y;
					enemy[y] = x;
					ans += count(x);
				} else if(enemy[x] == -1) {
					merge(enemy[y], x);
				} else {
					merge(enemy[x], y);
				}
			}
		}
		
		//for(int i = 0; i < k; i++) {
		//	if(par[i] < 0)
		//		std::cout << i << " " << enemy[i] << " " << choice[i] << " " << par[i] << " " << count(i) << std::endl;
		//}
		std::cout << ans << std::endl;
	}
	
	return 0;
}