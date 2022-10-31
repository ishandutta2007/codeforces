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
	int N, S;
	cin >> N >> S;
	S--;
	vector<int> A;
	int t;
	int res = 0;
	int w = 0;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (i == S) {
			if (t != 0) {
				res++;
			}
		}
		else {
			if (t == 0) {
				w++;
			}
			else {
				A.push_back(t);
			}
		}
	}
	res += w;
	sort(A.begin(), A.end());
	int l = 0;
	for (int i = 0; i < A.size(); i++) {
		if (l + 1 < A[i]) {
			
			if (w > 0) {
				w--;
			}
			else {
				A.pop_back();
				res++;
			}
			l++;
			i--;
		}
		else {
			l = A[i];
		}

	}


	cout << res << endl;
}