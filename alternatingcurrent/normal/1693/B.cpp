#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
int p[200200];
vector<int> v[200200];
ll l[200200], r[200200];
ll ans = 0;
ll dfs(int now){
	ll ret = 0;
	rep(i, (int)v[now].size())
		ret += dfs(v[now][i]);
	if(ret < l[now])
		ret = r[now], ans++;
	ret = min(ret, r[now]);
	return ret;
}

int main(){
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			v[i].clear();
		for(int i = 1; i < n; i++){
			cin >> p[i];
			p[i]--;
			v[p[i]].push_back(i);
		}
		rep(i, n)
			cin >> l[i] >> r[i];
		ans = 0;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}