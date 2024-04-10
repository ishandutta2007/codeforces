#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int p[200200];
vector<int> son[200200];
int bc[200200];
ll s[200200];
void gets(int now){
	if(now)
		s[now] += s[p[now]];
	rep(i, (int)son[now].size())
		gets(son[now][i]);
}
pair<ll, ll> dfs(int now){
	if(!(int)son[now].size())
		return make_pair(s[now] * bc[now], s[now]);
	
	vector<ll> pq;
	ll ans = 0;
	rep(i, (int)son[now].size()){
		bc[son[now][i]] = bc[now] / (int)son[now].size();
		pair<ll, ll> ret = dfs(son[now][i]);
		ans += ret.first;
		pq.push_back(ret.second);
	}
	sort(pq.rbegin(), pq.rend());
	
	int rem = bc[now] % (int)son[now].size();
	rep(i, rem)
		ans += pq[i];
	
	return make_pair(ans, pq[rem]);
}
void solve(){
	cin >> n >> k;
	rep(i, n)
		son[i].clear(), s[i] = 0;
	
	for(int i = 1; i < n; ++i)
		cin >> p[i], --p[i], son[p[i]].push_back(i);
	
	rep(i, n)
		cin >> s[i];
	gets(0);
	
	bc[0] = k;
	pair<ll, ll> ans = dfs(0);
	cout << ans.first << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}