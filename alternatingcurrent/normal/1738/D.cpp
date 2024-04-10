#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;
int n;
int b[100100];
vector<int> v[100100];

vector<int> ans;
void dfs(int now){
	if(now && now <= n) ans.push_back(now);
	sort(v[now].begin(), v[now].end(), [&](int x, int y){ return v[x].size() < v[y].size(); });
	rep(i, (int)v[now].size())
		dfs(v[now][i]);
}

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> b[i];
		
		vector< pair<int, int> > vb;
		for(int i = 1; i <= n; ++i)
			vb.emplace_back(b[i], i);
		sort(vb.begin(), vb.end());
		
		int k = 1, mn = n+1, p = 0;
		for(k = 0, p = 0; k <= n; ++k){
			while(p < n && vb[p].first == k)
				mn = min(mn, vb[p].second), ++p;
//			cout << k << " " << p << " " << mn << endl;
			if(p == n-k && mn == k+1)
				break;
		}
		
//		cout << "mid" << endl;
		
		rep(i, n+2)
			v[i].clear();
		for(int i = 1; i <= n; ++i)
			v[b[i]].push_back(i);
		
		ans.clear();
		if(!v[0].empty())
			dfs(0);
		else
			dfs(n+1);
		
		cout << k << "\n";
		rep(i, n)
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}