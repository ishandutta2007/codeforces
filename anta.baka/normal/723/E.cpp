#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

vector<multiset<int>> gr;
stack<int> s;
vector<int> path;

void findEulerPath(int v) {
	s.push(v);
	while(!s.empty()) {
		int w = s.top();
		if(gr[w].empty()) {
			s.pop();
			path.pb(w);
		} else {
			int to = (*gr[w].begin());
			s.push(to);
			gr[w].erase(gr[w].begin());
			gr[to].erase(gr[to].find(w));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);

	int tests;
	cin >> tests;
	while(tests--) {
		int n, m;
		cin >> n >> m;
		gr.assign(n, multiset<int>());
		set<pii> edges;
		vector<int> deg(n, 0);
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			gr[u].insert(v);
			gr[v].insert(u);
			++deg[u]; ++deg[v];
			edges.insert(mp(u,v));
			edges.insert(mp(v,u));
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(deg[i] % 2 == 0)
				ans++;
		cout << ans << "\n";
		vector<bool> vis(n, false);
		for(int i = 0; i < n; i++)
			if(vis[i] == false && deg[i] > 0) {
				vector<int> odd;
				queue<int> q;
				q.push(i);
				vis[i] = true;
				while(!q.empty()) {
					int v = q.front();
					q.pop();
					if(deg[v] % 2 == 1)
						odd.pb(v);
					for(int to : gr[v])
						if(vis[to] == false) {
							q.push(to);
							vis[to] = true;
						}
				}
				for(int j = sz(odd)-1; j > 0; j -= 2) {
					gr[odd[j]].insert(odd[j-1]);
					gr[odd[j-1]].insert(odd[j]);
				}
				path.clear();
				findEulerPath(i);
				for(int j = sz(path)-1; j > 0; j--)
					if(edges.find(mp(path[j-1],path[j])) != edges.end()) {
						cout << path[j-1]+1 << ' ' << path[j]+1 << "\n";
						edges.erase(mp(path[j-1],path[j]));
						edges.erase(mp(path[j],path[j-1]));
					}
			}
	}
}