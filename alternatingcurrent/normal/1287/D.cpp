#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int par[2020];
vector<int> son[2020];
int c[2020];
vector<int> order[2020];
int ans[2020];
int root = -1;

bool dfs(int now){
	rep(i, son[now].size()){
		if(!dfs(son[now][i])) return false;
	}
	vector<int> temp;
	rep(i, son[now].size()){
		int to = son[now][i];
		rep(j, order[to].size()){
			temp.push_back(order[to][j]);
		}
	}
	if(c[now] > temp.size()){
		return false;
	}
	rep(i, c[now]) order[now].push_back(temp[i]);
	order[now].push_back(now);
	for(int i = c[now]; i < temp.size(); i++) order[now].push_back(temp[i]);
	return true;
}

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &par[i], &c[i]);
		par[i]--;
		if(par[i] >= 0) son[par[i]].push_back(i);
		else root = i;
	}
	bool has_ans = dfs(root);
	if(!has_ans) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		rep(i, order[root].size()){
			ans[order[root][i]] = i+1;
		}
		rep(i, n) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}