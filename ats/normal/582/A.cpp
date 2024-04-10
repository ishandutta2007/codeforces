#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<int> res;
map<int, int> mp;
int gcd(int a, int b) {
	while(b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}
void pb(int a) {
	for (int i = 0; i < res.size(); i++) {
		int g = gcd(a, res[i]);
		mp[g] -= 2;
		if (mp[g] == 0) {
			mp.erase(g);
		}
	}
	mp[a] -= 1;
	if (mp[a] == 0) {
		mp.erase(a);
	}
	res.push_back(a);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	int a;
	for (int i = 0; i < N*N; i++) {
		cin >> a;
		mp[a]++;
	}
	vector<int> X;
	for (auto m : mp) {
		if (m.second % 2 == 1) {
			X.push_back(m.first);
		}
	}
	
	for (int i : X) {
		//cerr << i << endl;
		pb(i);
	}
	while (mp.size()) {
		auto t = mp.end();
		t--;
		pb((*t).first);
		pb((*t).first);
	}
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}