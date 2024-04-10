#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 70 * 1000 + 5;

int a[N];
bitset<N> dp;
bitset<N> dif;
bool mark[N];
int chld[N];
int first[N];
vector <pair <int, int> > v;
int main() {
	int n, s, maxi = 0;
	cin >> n >> s;
	long long sm = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sm += a[i];
		if (a[i] > a[maxi])
			maxi = i;
	}
	dp[0] = true;
	s -= a[maxi];
	mark[maxi] = true;
	for (int i = 1; i <= n; i++) {
		
		if (i != maxi) {
			dif = (dp << a[i]) & ~dp;
			for (int j = dif._Find_first(); j <= s; j = dif._Find_next(j)) {
				first[j] = i;
			}
			dp |= (dp << a[i]);
		}
		
	}	
	if (s < 0 || !dp[s]) {
		cout << -1 << endl;
		return 0;
	}
//	for (int i = n; i; i--) {
//		if (dp[i][s] && !dp[i - 1][s]) {
//			mark[i] = true;
//			s -= a[i];
//		}
//	}
	while (s != 0) {
		int x = first[s];
		mark[x] = true;
		s -= a[x];
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			v.push_back({a[i], i});
		}
	}
	sort(v.begin(), v.end());
	if (v.size()) {
		chld[maxi] = v.back().second;
	}
	for (int i = (int) v.size() - 1; i > 0; i--) {
		chld[v[i].second] = v[i - 1].second;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] - a[chld[i]] << " ";
		if (chld[i] == 0) 
			cout << 0 << endl;
		else {
			cout << 1 << " " << chld[i] << endl;
		}
	}
	return 0;
}