#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
struct edge{
	int to;
	int cap;
	int ind;
	bool dir;
};
edge make_edge(int to, int cap, int ind, int dir){
	edge ret;
	ret.to = to, ret.cap = cap, ret.dir = dir, ret.ind = ind;
	return ret;
}
vector<edge> v[200200];
ll sum[200200];
bool ans[200200];
bool used[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		v[a].push_back(make_edge(b, c, i, 0));
		v[b].push_back(make_edge(a, c, i, 1));
		sum[a] += c;
		sum[b] += c;
	}
	used[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int now = q.front(); q.pop();
//		cout << now << endl;
		used[now] = 1;
		rep(i, (int)v[now].size()){
			if(used[v[now][i].to]) continue;
			ans[v[now][i].ind] = v[now][i].dir;
			sum[v[now][i].to] -= v[now][i].cap + v[now][i].cap;
			if(sum[v[now][i].to] == 0 && v[now][i].to != n-1) q.push(v[now][i].to);
		}
	}
	rep(i, m) cout << ans[i] << endl;
	return 0;
}