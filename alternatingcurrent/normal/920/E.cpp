#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int lmt;
vector<int> v[200200];
bool used[200200];
int bel[200200];
bool no[200200];
bool ok[200200];
int sz[200200];

int dfs(int now){
	used[now] = 1;
	if(n - (int)v[now].size() > lmt){
		return -1;
	}
	rep(i, (int)v[now].size()) no[v[now][i]] = 1;
	vector<int> nxt;
	rep(i, n) if(!no[i]){
		if(used[i] && bel[i] != bel[now]){
			rep(j, (int)v[now].size()) no[v[now][j]] = 0;
			return -1;
		}
	}
	rep(i, n) if(!no[i] && !used[i]) nxt.push_back(i);
	rep(i, (int)v[now].size()) no[v[now][i]] = 0;
//	cout << now << endl;
	int sum = 1;
	rep(i, (int)nxt.size()){
		bel[nxt[i]] = bel[now];
		int val = dfs(nxt[i]);
		if(val < 0){
			return -1;
		}
		sum += val;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	lmt = 0;
	while(lmt < n && 1LL * lmt * (n - lmt) <= 1LL * m) lmt++;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b); 
		v[b].push_back(a);
	}
	vector<int> ans; 
	int anssum = 0;
	rep(i, n){
		if(!used[i]){
//			cout << "-----" << i << "-----" << endl;
			used[i] = 1;
			bel[i] = i;
			int val = dfs(i);
			ok[i] = (bool)(val > 0);
		}
	}
	rep(i, n) if(ok[bel[i]]) sz[bel[i]]++;
	rep(i, n) if(ok[i] && sz[i]) ans.push_back(sz[i]), anssum += sz[i];
	if(n - anssum > 0) ans.push_back(n - anssum);
	cout << (int)ans.size() << endl;
	sort(ans.begin(), ans.end());
	rep(i, (int)ans.size()) cout << ans[i] << " ";
	cout << endl;
	return 0;
}