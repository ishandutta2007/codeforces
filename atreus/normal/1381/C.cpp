#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int b[maxn], c[maxn], d[maxn];
vector<int> g[maxn];	

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		int n, x, y;
		cin >> n >> x >> y;
		for (int i = 1; i <= n+1; i++){
			c[i] = d[i] = 0;
			g[i].clear();
		}
		for (int i = 1; i <= n; i++){
			cin >> b[i];
			c[b[i]] ++;
		}
		vector<pair<int,int>> cols;
		for (int i = 1; i <= n+1; i++)
			cols.push_back({c[i], i});
		sort(cols.begin(), cols.end());
		d[cols[0].second] = n-y;
		for (int i = 0; i <= n; i++){
			int now = cols[i].second;
			if (c[now] >= y){
				d[now] += y;
				y = 0;
				break;
			}
			else{
				d[now] += c[now];
				y -= c[now];
			}
		}
		set<pair<int,int>> slast;
		for (int i = 1; i <= n+1; i++)
			if (c[i] and d[i])
				slast.insert({-c[i]-d[i], i});
		int m = n;
		while (x --){
			int idx = (*slast.begin()).second;
			slast.erase(slast.begin());
			g[idx].push_back(idx);
			c[idx] --, m --, d[idx] --;
			if (d[idx] and c[idx])
				slast.insert({-c[idx]-d[idx],idx});
		}
		bool flag = 0;
		for (int i = 1; i <= n+1; i++)
			if (d[i] > m-c[i])
				flag = 1;
		if (flag){
			cout << "NO\n";
			continue;
		}
		set<pair<int,int>> s;
		for (int i = 1; i <= n+1; i++)
			if (d[i])
				s.insert({-c[i]-d[i],i});
		set<pair<int,int>> s2;
		for (int i = 1; i <= n+1; i++)
			if (c[i] > 0)
				s2.insert({-c[i],i});
		while (!s.empty()){
			int idx1 = (*s.begin()).second;
			auto it = s2.begin();
			if ((*it).second == idx1)
				it ++;
			int idx2 = (*it).second;
			s2.erase({-c[idx2], idx2});
			if (d[idx2] > 0)
				s.erase({-c[idx2]-d[idx2],idx2});
			s.erase({-c[idx1]-d[idx1],idx1});
			g[idx2].push_back(idx1);
			d[idx1] --, c[idx2] --, m --;
			if (d[idx2] > 0)
				s.insert({-c[idx2]-d[idx2],idx2});
			if (d[idx1] > 0)
				s.insert({-c[idx1]-d[idx1],idx1});
			if (c[idx2] > 0)
				s2.insert({-c[idx2],idx2});
		}
		cout << "YES\n";
		for (int i = 1; i <= n; i++){
			cout << g[b[i]].back() << " ";
			g[b[i]].pop_back();
		}
		cout << '\n';
	}
}