#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
vector<int> v[100100];
int col[100100];
void dfs0(int now, int par){
	rep(i, (int)v[now].size())
		if(v[now][i] != par){
			col[v[now][i]] = -col[now];
			dfs0(v[now][i], now);
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			v[i].clear();
		rep(i, n - 1){
			int a, b;
			cin >> a >> b;
			a--, b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		col[0] = 1;
		dfs0(0, -1);
		cout << (int)v[0].size() << " ";
		for(int i = 1; i < n; i++)
			cout << (int)v[i].size() * col[i] << " ";
		cout << endl;
	}
	return 0;
}