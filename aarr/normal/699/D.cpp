#include <iostream>
#include <vector>
using namespace std;

int nparts = 0;

int par[200005];
int isCycle[200005];
int mark[200005];
vector <int> grandpar;
void dfs(int v) {
	int u = v;
	while (!mark[u]) {
		mark[u] = nparts;
		u = par[u];
	}
	if (mark[u] == nparts) {
		grandpar.push_back(u);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			nparts++;
			dfs(i);
		}
	}
	int greatpar = -1;
	for (int i = 0; i < grandpar.size(); i++) {
		if (par[grandpar[i]] == grandpar[i]) {
			greatpar = grandpar[i];
		}
	}
	if (greatpar > 0) {
		cout << grandpar.size() - 1 << endl;
		for (int i = 0; i < grandpar.size(); i++) {
			if (grandpar[i] != greatpar) {
				par[grandpar[i]] = greatpar;
			}
		}
	}
	else {
		cout << grandpar.size() << endl;
		greatpar = grandpar[0];
		for (int i = 0; i < grandpar.size(); i++) {
			par[grandpar[i]] = greatpar;
		}
	}
	//cout << grandpar.size();
	for (int i = 1; i <= n; i++) {
		cout << par[i] << " ";
	}
	return 0;
}