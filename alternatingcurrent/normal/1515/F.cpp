#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
ll x;
pair<int, int> e[300300];
map< pair<int, int>, int > mp;
bool used[300300];
vector<int> v[300300];
vector<int> son[300300]; 
ll subsum[300300];
ll val[300300];
bool cmp(int a, int b){
	return (subsum[a] > subsum[b]);
}
void dfs0(int now){
	used[now] = 1;
	subsum[now] = val[now];
	rep(i, (int)v[now].size()) if(!used[v[now][i]]) son[now].push_back(v[now][i]), dfs0(v[now][i]), subsum[now] = subsum[now] + subsum[v[now][i]] - x;
}
vector< pair<int, int> > ans;
void getans(int now){
	sort(son[now].begin(), son[now].end(), cmp);
	rep(i, (int)son[now].size()){
		if(subsum[son[now][i]] > 0){
			getans(son[now][i]);
			ans.push_back(make_pair(now, son[now][i]));
			subsum[now] += subsum[son[now][i]] - x;
		} else {
			subsum[son[now][i]] += subsum[now] - x;
			ans.push_back(make_pair(now, son[now][i]));
			getans(son[now][i]);
			subsum[now] = subsum[son[now][i]] - x;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	rep(i, n) cin >> val[i];
	ll sum = 0;
	rep(i, n) sum += val[i];
	rep(i, m){
		cin >> e[i].first >> e[i].second;
		e[i].first--, e[i].second--;
		v[e[i].first].push_back(e[i].second);
		v[e[i].second].push_back(e[i].first);
		mp[e[i]] = i;
		mp[make_pair(e[i].second, e[i].first)] = i;
	}
	if(sum < 1LL * (n - 1) * x){
		cout << "NO" << endl;
		return 0;
	}
	dfs0(0);
	getans(0);
	cout << "YES" << endl; 
	rep(i, n - 1) cout << mp[ans[i]] + 1 << endl;
	return 0;
}