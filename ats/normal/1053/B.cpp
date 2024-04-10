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
	vector<int> A(N);
	int res = 0;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A[i] = 0;
		while (a > 0) {
			A[i] += a % 2;
			a /= 2;
		}
	}
	vector<int> sum(N + 1, 0);
	vector<int> sum1(N + 1, 0); 
	vector<int> sum0(N + 1, 0);
	sum0[0] = 1;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + A[i];
		sum1[i + 1] = sum1[i] + (sum[i + 1] % 2);
		sum0[i + 1] = sum0[i] + 1 - (sum[i + 1] % 2);
	}
	//for (int i = 0; i < N; i++) {
	//	cerr << sum0[i] << " ";
	//}
	//cerr << endl;
	//for (int i = 0; i < N; i++) {
	//	cerr << sum1[i] << " ";
	//}
	//cerr << endl;
	vector<pair<int, int> >vp(N);
	vector<int> B(N, -1);
	set<int> st;
	st.insert(-1);
	st.insert(N);
	for (int i = 0; i < N; i++) {
		vp[i].first = A[i];
		vp[i].second = i;
	}
	sort(vp.rbegin(), vp.rend());
	for (int ii = 0; ii < vp.size(); ii++) {
		int i = vp[ii].second;
		int v = vp[ii].first;
		//cerr << i << " " << v << endl;
		B[i] = v;
		int l, r;
		st.insert(i);
		auto ss = st.find(i);
		ss--;
		l = (*ss);
		ss++; ss++;
		r = (*ss);

		int rr = i;
		int ll = i;
		while (sum[rr + 1] - sum[ll] < 2*v && ll > l) {
			ll--;
		}
		if (sum[rr + 1] - sum[ll] >= 2 * v) {
			//cerr << "ll rr" << ll << " " << rr << endl;
			if (l >= 0) {
				res += (sum0[ll] - sum0[l]) * (sum0[r] - sum0[rr]);
				res += (sum1[ll] - sum1[l]) * (sum1[r] - sum1[rr]);
			}
			else {
				res += (sum0[ll]) * (sum0[r] - sum0[rr]);
				res += (sum1[ll]) * (sum1[r] - sum1[rr]);
			}
		}
		//cerr << res << endl;
		ll++;
		for (; ll <= i; ll++) {
			while (sum[rr + 1] - sum[ll] < 2 * v && rr < r) {
				rr++;
			}
			if (sum[rr + 1] - sum[ll] >= 2 * v) {
				//cerr << "ll rr" << ll << " " << rr << endl;
				if (sum[ll] % 2 == 0) {
					res += sum0[r] - sum0[rr];
				}
				else {
					res += sum1[r] - sum1[rr];
				}
			}
		}
		//cerr << res << endl;
	}
	cout << res << endl;
}