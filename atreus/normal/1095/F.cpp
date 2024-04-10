#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;

bool mark[maxn];

ll dis[maxn];

vector <pair <int, ll> > g[maxn];

ll answer;

int n;

void prim(int idx){
	set <pair <ll, int> > s;
	for (int i = 1; i <= n; i++)
		s.insert({dis[i], i});
	while (!s.empty()){
		int v = (*s.begin()).second;
		s.erase(s.begin());
		answer += dis[v];
		mark[v] = 1;
		for (auto u : g[v]){
			if (!mark[u.first] and dis[u.first] > u.second){
				s.erase({dis[u.first], u.first});
				dis[u.first] = u.second;
				s.insert({dis[u.first], u.first});
			}
		}
	}
}

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;

	int idx = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] < a[idx])
			idx = i;
	}
	for (int i = 1; i <= m; i++){
		int v, u;
		ll w;
		cin >> v >> u >> w;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	for (int i = 1; i <= n; i++)
		dis[i] = a[i] + a[idx];
	dis[idx] = 0;
	prim(idx);
	cout << answer << endl;
}