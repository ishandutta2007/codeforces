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
	int N, M;
	cin >> N >> M;
	int INF = (int)1 << 50;
	vector<int> mn(N, INF);
	vector<int> cnt(N, 0);
	int a, b;
	vector<int> res(N, 0);
	for (int i = 0; i < M; i++) {
		cin >> a >> b; a--; b--;
		if (b < a)b += N;
		mn[a] = min(mn[a], b);
		cnt[a]++;
	}
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N; j++) {
			int p = (i + j) % N;

			if (cnt[p] > 0) {
				res[i] = max(res[i],j + N * (cnt[p] - 1) + mn[p] - p);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << res[i];
	}
	cout << endl;
}