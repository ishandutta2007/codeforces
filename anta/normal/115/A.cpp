#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int> >r;

int dfs(int x) {
	vector<int>&v = r[x];
	int t = 0;
	for(int i = 0; i < v.size(); i ++) {
		t = max(t, dfs(v[i]));
	}
	return 1 + t;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int>v;
	v.resize(n+1);
	for(int i = 1; i <= n; i ++){
		int y;
		scanf("%d", &y);
		v[i] = y;
	}
	r.resize(n+1);
	vector<int>t;
	for(int i = 1; i <= n; i ++) {
		if(v[i]==-1) r[0].push_back(i);
		else r[v[i]].push_back(i);
	}
	printf("%d\n", dfs(0) - 1);
	return 0;
}