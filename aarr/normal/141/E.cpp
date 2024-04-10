#include <iostream>
#include <vector>
using namespace std;

const int N = 1005, M = 100 * 1000 + 5;
int nparts;

vector <int> adj1[N];
vector <int> adj2[N];
pair <pair <int, int>, char> inc[M];
int part[N * 2];
int par[N];
bool mark[M];

void dfs1(int v) {
	for (auto u : adj1[v]) {
		if (part[u] == 0) {
			part[u] = part[v];
			dfs1(u);
		}
	}
}
int get_par(int v, int par[]) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v], par);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> inc[i].first.first >> inc[i].first.second >> inc[i].second;
		if (inc[i].second == 'M') {
			adj1[inc[i].first.first].push_back(inc[i].first.second);
			adj1[inc[i].first.second].push_back(inc[i].first.first);
		}
	}
	nparts = n;
	if (n % 2 == 0) {
		cout << -1 << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (part[i] == 0) {
				nparts++;
				part[i] = nparts;
				part[nparts] = nparts;
				dfs1(i);
			}
		}
		int cnt = nparts - n;
	//	cout << "73 " << cnt << endl;
		if (cnt - 1 > (n - 1) / 2) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 1; i <= m; i++) {
			if (inc[i].second == 'S') {
				int u = inc[i].first.first, v = inc[i].first.second;
				//cout << u << " " << v << " " << get_par(u, part) << " " << get_par(v, part) << endl;
				if (get_par(u, part) != get_par(v, part)) {
					v = get_par(v, part), u = get_par(u, part);
					part[u] = v;
					cnt--;
					mark[i] = true;
				}
			}
		}
	//	cout << "74 " << cnt << endl;
		if (cnt != 1) {
			cout << -1 << endl;
			return 0;
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			par[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			if (mark[i]) {
				int u = inc[i].first.first, v = inc[i].first.second;
				if (get_par(u, par) != get_par(v, par)) {
					v = get_par(v, par), u = get_par(u, par);
					par[u] = v;
					cnt++;
				}				
			}
		}
		for (int i = 1; i <= m; i++) {
			if (!mark[i] && inc[i].second == 'S' && cnt < (n - 1) / 2) {
				int u = inc[i].first.first, v = inc[i].first.second;
				if (get_par(u, par) != get_par(v, par)) {
					v = get_par(v, par), u = get_par(u, par);
					par[u] = v;
					mark[i] = true;
					cnt++;
				}				
			}
		}
		if (cnt != (n - 1) / 2) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 1; i <= m; i++) {
			if (inc[i].second == 'M') {
				int u = inc[i].first.first, v = inc[i].first.second;
				if (get_par(u, par) != get_par(v, par)) {
					v = get_par(v, par), u = get_par(u, par);
					par[u] = v;
					mark[i] = true;
					cnt++;
				}				
			}
		}		
		cout << n - 1 << endl;
		for (int i = 1; i <= m; i++) {
			if (mark[i]) {
				cout << i << " ";
			}
		}
		
	}
	return 0;
}