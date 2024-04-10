#include <iostream>
#include <vector>
using namespace std;

const int N = 2000 * 1000 + 7;

vector <pair <int, int> > adj[N];
vector <int> tour;
bool mark[N];
bool markv[N];
bool isreal[N];
vector <int> odd;
int app[N];
pair <int, int> inc[N];
vector <pair <int, int> > ans;
void euler(int v) {
	markv[v] = true;
	while (adj[v].size()) {
		int u = adj[v].back().first, a = adj[v].back().second;
		adj[v].pop_back();
		if (mark[a] == false) {
			mark[a] = true;
			euler(u);
			tour.push_back(a);
		}
	}
}
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u;
		cin >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		inc[i] = {u, v};
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() % 2 == 1) {
			odd.push_back(i);
		}
	}
	for (int i = 0; i < odd.size(); i += 2) {
		int v = odd[i], u = odd[i + 1];
		adj[u].push_back({v, m + i / 2 + 1});
		adj[v].push_back({u, m + i / 2 + 1});
		inc[m + i / 2 + 1] = {u, v};
		
	}
	for (int i = 1; i <= n; i++) {
		if (markv[i] == false) {
			tour.clear();
			euler(i);
			//cout << tour.size() << "\n";
			for (int i = 0; i < tour.size(); i += 2) {
				if (tour[i] <= m) {
					//cout << i << endl;
					app[tour[i]] = true;
				}
				else {
					i--;
					//cout << i << endl;
					if (i == -1)
						app[tour.back()] = true;
					else {
						app[tour[i]] = true;
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (app[i] == true) {
			ans.push_back(inc[i]);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}