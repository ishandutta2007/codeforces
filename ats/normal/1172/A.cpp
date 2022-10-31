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
	vector<int> B(N);
	int res = 0;
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] > 0)st.insert(A[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	res = -1;
	int l = 0;
	for (int i = 0; i < N; i++) {
		if (B[i] == 1) {
			bool ok = true;
			for (int j = 0; j < N; j++) {
				if (B[j + l] != j + 1) {
					ok = false;
				}
			}
			if (ok) {
				res = i;
			}
			else {
				for (int j = l; j < N; j++) {
					if (B[j] > 0) {
						//cerr << j << " " << i + 2 - B[j] + N << endl;
						res = max(res, j + 2 - B[j] + N);
					}
				}
			}
			

			break;
		}

		if (st.size() > 0) {
			int k = (*st.begin());
			B.push_back(k);
			st.erase(k);

		}
		else {
			B.push_back(0);
		}

		if (B[i] > 0) {
			st.insert(B[i]);
		}
		l++;


	}
	if (res == -1) {
	    res = N;
		for (int j = 0; j < N; j++) {
			if (B[j] > 0) {
				//cerr << j << " " << j + 2 - B[j] + N << endl;
				res = max(res, j + 2 - B[j] + N);
			}
		}
	}



	cout << res << endl;
}