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
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		//A[i] = N - i;
	}
	//vector<vector<int> > B(N - 1, vector<int>(N, 0));
	/*for (int k = 1; k <= N - 1; k++) {
		for (int i = 1; i <= N; i++) {
			cerr << (i + k - 2) / k << " ";
		}
		cerr << endl;
	}*/
	int t;
	int bt;
	vector<int> res(N - 1, 0);
	for (int j = 1; j < N; j++) {
		bt = N + 1;
		for (int k = 1; k <= j; k++) {
			t = (j - 1) / k;
			
			if (t < bt) {
				//cerr << j << " " << k << " " << t << endl;
				//B[t][j] = k;
				/*if (t >= 1 && A[((j + t - 1) / (t)) - 1] > A[j]) {
					res[t]--;
				}*/
				if (A[k - 1] > A[j]) {
					res[t]++;
					if (bt != N + 1) {
						res[bt]--;
					}
				}

			}
			else {
				break;
			}
			bt = t;
		}
		bt--;
		while (bt >= 0) {
			//B[bt][j] = (j + bt) / (bt + 1);
			if (A[((j + bt) / (bt + 1)) - 1] > A[j]) {
				res[bt]++;
				res[bt + 1]--;
			}
			bt--;
		}
	}
	/*for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			cerr << B[i][j] << " ";
		}
		cerr << endl;
	}*/
	for (int i = 1; i < N - 1; i++) {
		res[i] += res[i - 1];
	}
	for (int i = 0; i < N - 1; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}