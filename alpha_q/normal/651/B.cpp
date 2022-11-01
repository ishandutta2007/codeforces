#include <bits/stdc++.h>

using namespace std;

int n, i, ret; 
vector <int> V;
map <int, int> F;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		int x; cin >> x;
		F[x]++;
	}
	V.push_back(0);
	for (auto it : F) V.push_back(it.second);
	sort(V.begin(), V.end());
	
	ret = 0; int sz = V.size() - 1;
	for (i = 1; i < V.size(); i++) ret += (V[i] - V[i - 1]) * (--sz);
	cout << ret << endl;
	return 0;
}