/*
 
 
 
 
 
 





 
 

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int h; cin >> h;
	vector<int> a(h + 1);
	for(int i = 0; i < h + 1; i++) cin >> a[i];
	bool single = true;
	for(int i = 1; i < h + 1; i++) single &= (a[i - 1] < 2 || a[i] < 2);
	if(single) return cout << "perfect", 0;
	cout << "ambiguous\n";
	int n = 0;
	vector<vector<int>> lvl(h + 1);
	for(int i = 0; i < h + 1; i++) {
		for(int j = 0; j < a[i]; j++) lvl[i].push_back(n + j);
		n += a[i];
	}
	vector<int> anc(n, 0);
	for(int i = 1; i < h + 1; i++) {
		for(int j : lvl[i]) anc[j] = lvl[i - 1][0] + 1;
	}
	for(int i = 0; i < n; i++) cout << anc[i] << ' ';
	cout << endl;
	for(int i = 1; i < h + 1; i++)
		if(a[i - 1] >= 2 && a[i] >= 2) {
			anc[lvl[i].back()] = lvl[i - 1].back() + 1;
			break;
		}
	for(int i = 0; i < n; i++) cout << anc[i] << ' ';
}