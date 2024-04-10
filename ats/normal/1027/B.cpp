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
	int N, Q;
	cin >> N >> Q;
	int a, b;
	vector<int> res(Q);
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		a--;
		b--;
		int v = a*N + b + 1;
		res[i] = (v + (((a + b) % 2 == 0) ? 0 : N*N) + 1) / 2;
	}
	for (int i = 0; i < Q; i++) {
		cout << res[i] << endl;
	}
}