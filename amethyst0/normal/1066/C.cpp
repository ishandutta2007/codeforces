#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 200010;

int l[maxn], r[maxn];
int tm[maxn];
int pref_sum_l[maxn], pref_sum_r[maxn];

int get_sum_l(int l, int r) {
	if (l == 0) {
		return pref_sum_l[r];
	}

	return pref_sum_l[r] - pref_sum_l[l - 1];
}

int get_sum_r(int l, int r) {
	if (l == 0) {
		return pref_sum_r[r];
	}

	return pref_sum_r[r] - pref_sum_r[l - 1];
}

int main() {
	//L id
	//           (0)   (sz).
	//   R id.
	//      ,   - ,  ? id
	//id     tm,          ,   .
	
	//          ,        time    
	//   .

	int q;

	cin >> q;
	int sz = 0;

	int cnt_l = 0, cnt_r = 0;

	for (int i = 0; i < q; i++) {
		char c;
		int id;

		cin >> c >> id;

		if (c == '?') {
			//            ?
			int cur_l = l[id];
			int cur_r = r[id];

			//         tm[id] + 1  (i - 1)
			cur_l += get_sum_l(tm[id] + 1, i - 1);
			cur_r += get_sum_r(tm[id] + 1, i - 1);

			cout << min(cur_l, cur_r) << endl;
		}
		else if (c == 'L') {
			tm[id] = i;
			l[id] = 0;
			r[id] = sz;
			sz += 1;
			cnt_l += 1;
		}
		else {
			tm[id] = i;
			l[id] = sz;
			r[id] = 0;
			sz += 1;
			cnt_r += 1;
		}

		pref_sum_l[i] = cnt_l;
		pref_sum_r[i] = cnt_r;
	}

	//system("pause");

	return 0;
}