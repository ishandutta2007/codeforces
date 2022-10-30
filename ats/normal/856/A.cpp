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
int X[1000001];
signed main() {
	int t;
	vector<int> A;
	vector<int> res;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		res.clear();
		A.clear();
		A.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		for (int i = 0; i < 1000001; i++) {
			X[i] = 0;
		}
		
		for (int i = 1; i < 1000001; i++) {
			if (X[i] == 0) {
				res.push_back(i);
				for (int j = 0; j < N; j++) {
					for (int k = j + 1; k < N; k++) {
						if (i + A[k] - A[j] < 1000001) {
							X[i + A[k] - A[j]] = 1;
						}
					}
				}
				if (res.size() >= N)break;
			}

		}
		if (res.size() < N) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (int i = 0; i < N; i++) {
				if (i > 0)cout << " ";
				cout << res[i];
			}
			cout << endl;
		}
	}

}