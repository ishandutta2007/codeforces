#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

string type[maxn];
int Lef[maxn], Rig[maxn];
bool a[maxn], mark[maxn];

void DFS (int u) {
	if (type[u] == "IN")
		mark[u] = 1;
	
	else if (type[u] == "NOT")
		DFS (Lef[u]);

	else if (type[u] == "AND") {
		if (a[Lef[u]] == 1)
			DFS (Rig[u]);
		if (a[Rig[u]] == 1)
			DFS (Lef[u]);
	}

	else if (type[u] == "OR") {
		if (a[Lef[u]] == 0)
			DFS (Rig[u]);
		if (a[Rig[u]] == 0)
			DFS (Lef[u]);
	}
	
	else {
		DFS (Lef[u]);
		DFS (Rig[u]);
	}
}

void dfs (int u) {
	if (type[u] == "IN")
		return;

	if (type[u] == "NOT") {
		dfs (Lef[u]);
		a[u] = !a[Lef[u]];
	}

	else {
		dfs (Lef[u]);
		dfs (Rig[u]);
		if (type[u] == "AND")
			a[u] = (a[Lef[u]] and a[Rig[u]]);
		if (type[u] == "OR")
			a[u] = (a[Lef[u]] or a[Rig[u]]);
		if (type[u] == "XOR")
			a[u] = (a[Lef[u]] xor a[Rig[u]]);
	}
}

int main () {
	ios_base::sync_with_stdio (false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> type[i];
		if (type[i] == "IN") 
			cin >> a[i];
		else if (type[i] == "NOT") {
			int u;
			cin >> u;
			Lef[i] = u;
		}
		else {
			int u, w;
			cin >> u >> w;
			Lef[i] = u;
			Rig[i] = w;
		}
	}

	dfs (1);

	DFS (1);

	for (int i = 1; i <= n; i++) {
		if (type[i] == "IN") {
			if (!mark[i])
				cout << a[1];
			else
				cout << !a[1];
		}
	}
	cout << endl;
}