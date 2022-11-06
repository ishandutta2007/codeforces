#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> deg(n+1, 0);
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		++deg[u], ++deg[v];
	}
	for(int i = 1; i<= n; ++i)
		if(deg[i] == 2) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}