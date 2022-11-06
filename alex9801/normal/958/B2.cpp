#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using pi = pair<int, int>;

int n;
vector<int> gph[MAXN];

pi dfs(int x, int p){
	pi ret(0, x);
	for(auto &i : gph[x]){
		if(i == p) continue;
		auto r =dfs(i, x);
		r.first++;
		ret = max(ret, r);
	}
	return ret;
}

vector<int> backup;

int dfs2(int x, int p){
	vector<int> mx;
	for(auto &i : gph[x]){
		if(i == p) continue;
		int v = dfs2(i, x);
		mx.push_back(v);
	}
	if(mx.empty()) return 1;
	sort(mx.begin(), mx.end());
	for(int i=0; i<mx.size()-1; i++) backup.push_back(mx[i]);
	return mx.back() + 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	int rt = dfs(1, -1).second;
	backup.push_back(dfs2(rt, -1));
	sort(backup.rbegin(), backup.rend());
	printf("1 ");
	int ans = 0;
	for(int i=2; i<=n; i++){
		if(i - 2 < backup.size()) ans += backup[i - 2];
		printf("%d ", ans);
	}
}