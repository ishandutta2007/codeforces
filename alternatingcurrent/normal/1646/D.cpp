#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n;
vector<int> v[200200];
pair<int, int> dp[2][200200];
pair<int, int> operator +(pair<int, int> a, pair<int, int> b){
	return make_pair(a.first + b.first, a.second + b.second);
} 
bool operator <(pair<int, int> a, pair<int, int> b){
	if(a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}
pair<int, int> qmax(pair<int, int> a, pair<int, int> b){
	return (a < b) ? b : a;
}
void dfs(int now, int par){
	dp[1][now] = make_pair(1, (int)v[now].size()), dp[0][now] = make_pair(0, 0);
	rep(i, (int)v[now].size()){
		if(v[now][i] != par){
			dfs(v[now][i], now); 
			dp[1][now] = dp[1][now] + dp[0][v[now][i]];
			dp[0][now] = dp[0][now] + qmax(dp[0][v[now][i]], dp[1][v[now][i]]);
		}
	}
}
bool in[200200];
void getpath(int now, int par, bool tp){
	in[now] = tp;
	rep(i, (int)v[now].size()){
		if(v[now][i] != par)
			getpath(v[now][i], now, (tp ? 0 : ((dp[1][v[now][i]] < dp[0][v[now][i]]) ? 0 : 1)));
	}
}

int ans[200200];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(n == 2){
		cout << "2 2" << endl << "1 1" << endl;
		return 0;
	}
	dfs(0, -1);
	cout << qmax(dp[1][0], dp[0][0]).first << " ";
	getpath(0, -1, (dp[1][0] < dp[0][0]) ? 0 : 1);
	int sum = 0;
	rep(i, n){
		ans[i] = (in[i] ? (int)v[i].size() : 1);
		sum += ans[i];
	}
	cout << sum << endl;
	rep(i, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}