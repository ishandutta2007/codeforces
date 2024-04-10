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
void re1(vector<pair<int, int> > &vp) {

	while (true) {
		if ((int)vp.size() < 2)break;

		if (vp[(int)vp.size() - 2].second <= vp.back().second) {
			vp.pop_back();
		}
		else {
			break;
		}
	}
}
void re2(vector<pair<int, int> > &vp) {
	while (true) {
		if ((int)vp.size() < 3)break;
		int sz = vp.size();
		int dxL = vp[sz - 2].first - vp[sz - 3].first;
		int dyL = vp[sz - 3].second - vp[sz - 2].second;
		int dxR = vp[sz - 1].first - vp[sz - 2].first;
		int dyR = vp[sz - 2].second - vp[sz - 1].second;

		if (dyL * dxR <= dyR * dxL) {
			swap(vp[sz - 2], vp[sz - 1]);
			vp.pop_back();
		}
		else {
			break;
		}
	}

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	int a, k, b, s;
	vector<pair<int, int> > vp;
	int ofs = 0;
	vp.emplace_back(0, 0);
	vector<pair<int, int> > res(Q);
	for (int i = 0; i < Q; i++) {
		cin >> a;
		if (a == 1) {
			cin >> k;
			
			ofs -= k;
			vp.clear();
			vp.emplace_back(ofs, 0);
			res[i].first = 0;
			res[i].second = 0;
		}
		else if (a == 2) {
			cin >> k;
			vp.emplace_back(N, 0);
			N += k;
			re1(vp);
			re2(vp);
			res[i].first = vp.back().first - ofs;
			res[i].second = vp.back().second;

		}
		else {
			cin >> b >> s;
			for (int j = 0; j < vp.size(); j++) {
				vp[j].second += b + (vp[j].first - ofs) * s;
			}
			re1(vp);
			re2(vp);
			res[i].first = vp.back().first - ofs;
			res[i].second = vp.back().second;
		}
		//cerr << vp[0].first << " " << vp[0].second << " " << ofs << endl;

	}

	for (int i = 0; i < Q; i++) {
		cout << res[i].first + 1 << " " << res[i].second << endl;
	}
}