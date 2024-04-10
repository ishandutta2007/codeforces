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
	int N;
	cin >> N;
	vector<int> V(N);
	vector<int> D(N);
	vector<int> P(N);
	vector<int> res;
	for (int i = 0; i < N; i++) {
		cin >> V[i] >> D[i] >> P[i];
	}
	vector<int> rem;
	for (int i = 0; i < N; i++) {
		rem.push_back(i);
	}
	for (int first = 0; first < N; first++) {
		if (rem.size() == 0)break;
		if (rem[0] > first)continue;
		/*cerr << first << endl;
		for (int i : rem) {
			cerr << P[i] << " ";
		}
		cerr << endl;*/

		int v = V[rem[0]] + 1;
		res.push_back(rem[0] + 1);
		int e = 0;
		for (int i : rem) {
			P[i] -= v + e;
			if (P[i] < 0 && i != rem[0])e += D[i];
			if (v > 0)v--;
		}
		vector<int> nr;
		for (int i : rem) {
			if (P[i] >= 0 && i != rem[0]) {
				nr.push_back(i);
			}
		}
		swap(rem, nr);
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}