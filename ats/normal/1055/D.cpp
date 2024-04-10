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
int *buildFail(string p) {
	int m = p.size();
	int *fail = new int[m + 1];
	int j = fail[0] = -1;
	for (int i = 1; i <= m; ++i) {
		while (j >= 0 && p[j] != p[i - 1]) j = fail[j];
		fail[i] = ++j;
	}
	return fail;
}
int match(string t, string p, int *fail) {
	int n = t.size(), m = p.size();
	int count = 0;
	for (int i = 0, k = 0; i < n; ++i) {
		while (k >= 0 && p[k] != t[i]) k = fail[k];
		if (++k >= m) {
			return i - m + 1;
		}
	}
	return -1;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<string> A(N);
	vector<string> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	vector<int> L(N, -1);
	int len = 0;
	int t;
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			L[i] = -1;
		}
		else {
			t = i;
			for (int j = 0; j < A[i].size(); j++) {
				if (A[i][j] != B[i][j]) {
					if (L[i] == -1) {
						L[i] = j;
					}
				}
			}
		}
	}
	char a, b;
	bool ok = true;
	while (ok) {
		if (L[t] + len >= (int)A[t].size()) {
			ok = false;
			break;
		}
		a = A[t][L[t] + len];
		b = B[t][L[t] + len];
		for (int i = 0; i < N; i++) {
			if (L[i] != -1) {
				if (L[i] + len >= (int)A[i].size()) {
					ok = false;
					break;
				}
				if (a != A[i][L[i] + len] || b != B[i][L[i] + len]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			len++;
		}
	}
	ok = true;
	while (ok) {
		if (L[t] <= 0) {
			ok = false;
			break;
		}
		a = A[t][L[t] - 1];
		b = B[t][L[t] - 1];
		for (int i = 0; i < N; i++) {
			if (L[i] != -1) {
				if (L[i] <= 0) {
					ok = false;
					break;
				}
				if (a != A[i][L[i] - 1] || b != B[i][L[i] - 1]) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			for (int i = 0; i < N; i++) {
				if (L[i] > 0)L[i]--;
			}
			len++;
		}
	}
	/*cerr << "O" << endl;
	KMP tmp("a");
	tmp.search("aaaaaa");
	for (auto i : tmp.res) {
		cerr << i << " ";
	}
	cerr << endl;*/

	string res1 = A[t].substr(L[t], len);
	string res2 = B[t].substr(L[t], len);

	bool yes = true;
	if (len == 0) yes = false;
	else {

		for (int i = 0; i < N; i++) {
			
			//cerr << A[i] << res1 << endl;
			int s = match(A[i], res1, buildFail(res1));
			if (s >= 0) {
				
				//cerr << i << " " << s << endl;
				for (int j = s; j < s + len; j++) {
					A[i][j] = res2[j - s];
				}
			}
			//cerr << A[i] << " " << B[i] << endl;
			if (A[i] != B[i]) {
				yes = false;
				break;
			}
		}
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j + len <= (int)A[i].size() ; j++) {
		//		if (A[i].substr(j, len) == res1) {
		//			for (int k = 0; k < len; k++) {
		//				A[i][k + j] = res2[k];
		//			}
		//			break;
		//		}
		//	}
		//	//cerr << A[i] << " " << B[i] << endl;
		//	if (A[i] != B[i]) {
		//		yes = false;
		//		break;
		//	}
		//}
	}
	if (yes) {
		cout << "YES" << endl;
		cout << res1 << endl;
		cout << res2 << endl;
	}
	else {
		cout << "NO" << endl;
	}
}