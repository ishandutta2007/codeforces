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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> h(N);
	int res = 0;
	int mn = (int)1e9;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		mn = min(mn, h[i]);
	}
	for (int i = 0; i < N; i++)h[i] -= mn;
	sort(h.begin(), h.end());
	int cur = 0;
	int removed = 0;
	for (int i = h.back(); i >= 1; i--) {
		int t = h.end() - lower_bound(h.begin(), h.end(), i);
		//cerr << i << " " << t << endl;
		cur += t;
		if (cur - removed > K) {
			removed = cur - t;
			res++;
		}
	}
	if (removed != cur) {
		res++;
	}
	cout << res << endl;
}