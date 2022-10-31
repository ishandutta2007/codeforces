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
#include <bitset>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<bitset<7001> > A(N, 0);
	bitset<7001> ZERO = bitset<7001>(0);
	string res;
	vector<bitset<7001> > ya(7001, 0);
	for (int i = 1; i <= 7000; i++) {
		for (int j = 1; j*j <= i; j++) {
			if (i % j == 0) {
				ya[i][j] = true;
				ya[i][i / j] = true;
			}
		}
	}
	//cerr << "OK" << endl;
	vector<int> X;
	for (int i = 1; i <= 7000; i++) {
		int t = i;
		bool ok = true;
		for (int j = 2; j*j <= t; j++) {
			if (t % j == 0) {
				t /= j;
				if (t % j == 0) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			X.push_back(i);
		}
	}
	/*for (int i = 0; i < 20; i++) {
		cerr << X[i] << " ";
	}
	cerr << endl;*/
	vector<bitset<7001> > pre(7001, 0); 
	for (int i = 1; i <= 7000; i++) {
		for (int j = 0; j < X.size(); j++) {
			if (i * X[j] > 7000)break;
			pre[i][i * X[j]] = true;
		}
	}
	bitset<7001> tmp;
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, v;
			cin >> x >> v; x--;
			A[x] = ya[v];

		}
		else if (t == 2) {
			int x, y, z;
			cin >> x >> y >> z; x--; y--; z--;
			A[x] = A[y] ^ A[z];
		}
		else if (t == 3) {
			int x, y, z;
			cin >> x >> y >> z; x--; y--; z--;
			A[x] = A[y] & A[z];
		}
		else {
			int x, v;
			cin >> x >> v; x--;
			bool a = false;
			/*if (v <= 50) {

			}
			else {
				for()
			}*/

			tmp = A[x] & pre[v];
			res.push_back((tmp.count() % 2) + '0');
		}
	}
	cout << res << endl;
}