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
#include <assert.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> L(N);
	vector<int> R(N);
	vector<int> U(N);
	vector<int> D(N);
	map<int, int> l, r, u, d;
	for (int i = 0; i < N; i++) {
		cin >> L[i] >> D[i] >> R[i] >> U[i];
		l[L[i]]++;
		d[D[i]]++;
		u[U[i]]++;
		r[R[i]]++;
	}
	int mxl;
	int mnr;
	int mxd;
	int mnu;

	auto ll = l.end(); ll--;
	mxl = (*ll).first;
	auto rr = r.begin();
	mnr = (*rr).first;
	auto dd = d.end(); dd--;
	mxd = (*dd).first;
	auto uu = u.begin();
	mnu = (*uu).first;
	int mxl2;
	int mnr2;
	int mxd2;
	int mnu2;
	//cerr << mxl << " " << mxd << " " << mnr << " " << mnu << endl;
	for (int i = 0; i < N; i++) {
		mxl2 = mxl;
		mnr2 = mnr;
		mxd2 = mxd;
		mnu2 = mnu;
		if (L[i] == mxl) {
			if ((*ll).second == 1) {
				ll--; mxl2 = (*ll).first; ll++;
			}
		}
		if (R[i] == mnr) {
			if ((*rr).second == 1) {
				rr++; mnr2 = (*rr).first; rr--;
			}
		}
		if (D[i] == mxd) {
			if ((*dd).second == 1) {
				dd--; mxd2 = (*dd).first; dd++;
			}
		}
		if (U[i] == mnu) {
			if ((*uu).second == 1) {
				uu++; mnu2 = (*uu).first; uu--;
			}
		}
		//cerr << i << endl;
		//cerr << mxl2 << " " << mxd2 << " " << mnr2 << " " << mnu2 << endl;
		if (mxd2 <= mnu2 && mxl2 <= mnr2) {
			cout << mxl2 << " " << mxd2 << endl;
			return 0;
		}
	}
	assert(false);
}