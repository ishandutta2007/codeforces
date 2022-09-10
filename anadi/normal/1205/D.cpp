#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int pod[N];
bool good[N];
vector <int> G[N];

int getSize(int u, int p){
	pod[u] = 1;
	for(auto v: G[u])
		if(v != p)
			pod[u] += getSize(v, u);
	return pod[u];
}

int centroid(int u){
	getSize(u, u);
	int half = (pod[u] + 1) / 2;
	bool change = true;
	
	while(change){
		change = false;
		for(auto v: G[u])
			if(pod[v] < pod[u] && pod[v] >= half){
				change = true;
				u = v;
				break;
			}
	}
	
	return u;
}

int sz, last = 0;
void go(int u, int p, int val){
	++last;
	printf("%d %d %d\n", u, p, last - val);
	
	val = last;
	for(auto v: G[u])
		if(v != p)
			go(v, u, val);
}

void go2(int u, int p, int val){
	last += sz;
	printf("%d %d %d\n", u, p, last - val);
	
	val = last;
	for(auto v: G[u])
		if(v != p)
			go2(v, u, val);
}

void solve(int root){
	vector <PII> sons;
	for(auto v: G[root])
		sons.push_back({pod[v], v});
	sort(sons.begin(), sons.end());
	
	int pt = (n + 2) / 3;
	int cur = 0;
	
	while(cur < pt){
		cur += sons.back().st;
		good[sons.back().nd] = true;
		sons.pop_back();
	}
	
	sz = cur + 1;
	for(auto v: G[root])
		if(good[v])
			go(v, root, 0);
	
	last = 0;
	for(auto v: G[root])
		if(!good[v])
			go2(v, root, 0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(n == 1)
		return 0;
	
	if(n == 2){
		printf("%d %d %d\n", 1, 2, 1);
		return 0;
	}
	
	int root = centroid(1);
	getSize(root, root);
	solve(root);
	return 0;
}