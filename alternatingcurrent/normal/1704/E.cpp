#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int T;
int n, m;
ll a[1010];
vector<int> v[1010];
int indeg[1010];
vector<int> ord;
vector< pair<int, ll> > dp[1010];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			v[i].clear(), indeg[i] = 0, dp[i].clear();
		ord.clear();
		rep(i, m){
			int a, b;
			cin >> a >> b;
			a--, b--;
			indeg[b]++;
			v[a].push_back(b);
		}
		queue<int> q;
		rep(i, n)
			if(!indeg[i])
				q.push(i);
		while(!q.empty()){
			int now = q.front(); 
			q.pop();
			ord.push_back(now);
			rep(i, (int)v[now].size()){
				indeg[v[now][i]]--;
				if(!indeg[v[now][i]])
					q.push(v[now][i]);
			}
		}
		rep(i, n){
			int id = ord[i];
			if(a[id])
				dp[id].push_back(make_pair(0, a[id] - 1));
			sort(dp[id].begin(), dp[id].end());
			vector< pair<int, ll> > now;
			rep(j, (int)dp[id].size()){
				if(!now.empty() && dp[id][j].first <= now[(int)now.size() - 1].second)
					now[(int)now.size() - 1].second += (dp[id][j].second - dp[id][j].first + 1);
				else
					now.push_back(dp[id][j]);
			}
			if(now.empty())
				continue;
//			cout << i << " " << id << ": ";
//			rep(i, (int)now.size()) cout << "(" << now[i].first << " " << now[i].second << ")  ";
//			cout << endl;
			if(now[(int)now.size() - 1].second >= Mod + Mod)
				now[(int)now.size() - 1].second = (now[(int)now.size() - 1].second % Mod + Mod);
			dp[id] = now;
			rep(j, (int)v[id].size())
				rep(k, (int)dp[id].size()){
//					cout << id << " to " << v[id][j] << " with (" << dp[id][k].first + 1 << ", " << dp[id][k].second + 1 << ") " << endl;
					dp[v[id][j]].push_back(make_pair(dp[id][k].first + 1, dp[id][k].second + 1));
				}
		}
		if(dp[ord[n - 1]].empty())
			cout << "0" << endl;
		else
			cout << (dp[ord[n - 1]][(int)dp[ord[n - 1]].size() - 1].second + 1) % Mod << endl;
	}
	return 0;
}