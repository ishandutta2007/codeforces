#include<bits/stdc++.h>

using namespace std;

const int MX = 300000;

int n;
unordered_map<long long, bool> forbiden;
vector<int> good, bad, comp[MX];

bool canMerge(int x, int y) {
	for (int u : comp[x])
		for (int v : comp[y])
			if (forbiden.count(u * 1ll * n + v) == 0)
				return true;
	
	return false;
}

void merge(int x, int y) {
	if (comp[x].size() < comp[y].size()) swap(comp[x], comp[y]);
	
	for (int z : comp[y]) comp[x].push_back(z);
}

bool tryMerge(int x, int y) {
	if (canMerge(x, y)) {
		merge(x, y);
		
		return true;
	}
	
	return false;
}

void justAdded(int x, int v) {
	vector<int> added;
	for (int j = 0; j < (int)bad.size(); j++)
		if (forbiden.count(bad[j] * 1ll * n + v) == 0) {
			added.push_back(bad[j]);
			merge(x, bad[j]);
			
			bad[j] = bad.back();
			bad.pop_back();
			j--;
		}
	
	for (int u : added) justAdded(x, u);
}

bool can[MX];

int main() {
	int m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		
		forbiden[u * 1ll * n + v] = true;
		forbiden[v * 1ll * n + u] = true;
	}
	
	for (int i = 1; i < n; i++) {
		comp[i].push_back(i);
		if (forbiden.count(i) == 0)
			good.push_back(i);
	}
	
	for (int i = 1; i < n; i++) {
		if (forbiden.count(i) == 0) continue;
		
		bool ok = false;
		for (int x : good) 
			if (tryMerge(x, i)) {
				ok = true;
				
				justAdded(x, i);
				
				break;
			}
		
		if (ok == false) bad.push_back(i);
	}
	
	if ((int)bad.size() > 0 || (int)good.size() < k) {
		printf("impossible\n");
		
		return 0;
	}
	
	for (int i = 0; i < (int)good.size(); i++) {
		for (int j = 0; j < i; j++)
			can[j] = canMerge(good[i], good[j]);
		
		for (int j = i - 1, p = i; j >= 0; j--)
			if (can[j]) {
				merge(good[j], good[p]);
				
				good[p] = good[i];
				good[i] = good.back();
				good.pop_back();
				p = j;
				i--;
			}
	}
	
	if ((int)good.size() > k) printf("im");
	
	printf("possible\n");
	
	return 0;
}