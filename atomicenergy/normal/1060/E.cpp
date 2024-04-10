#include <bits/stdc++.h>
using namespace std;


long long n;
vector<vector<long long> > g;
map<long long, long long> m;
map<long long, long long> f;

long long total;
long long dfs(long long v, long long p){
	if(p==-1){
		m[v] = 0;
	}else{
		m[v] = 1-m[p];
	}
	f[m[v]]++;
	long long tot = 1;
	for(long long x : g[v]){
		if(x==p) continue;
		long long y = dfs(x, v);
		total += y * (n-y);
		tot += y;
	}
	return tot;
}

int main() {
	total = 0;
	cin >> n;
	
	for(long long i=0; i<n; i++){
		vector<long long> u;
		g.push_back(u);
	}
	for(long long i=0; i<n-1; i++){
		long long x, y;
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	dfs(0, -1);
	total += f[0] * f[1];
	cout << total/2 << endl;
	return 0;
}