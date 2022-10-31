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
	vector<int> A;
	vector<int> B;
	int res = 0;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t != 0) {
			A.push_back(t);
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t != 0) {
			B.push_back(t);
		}
	}
	if ((int)A.size() > 0) {
		t = A[0];
		vector<int> C;
		for (int i = 0; i < B.size(); i++) {
			if (B[i] == t) {
				for (int j = 0; j < B.size(); j++) {
					C.push_back(B[(i + j) % B.size()]);
				}
				break;
			}
		}
		
		swap(B, C);
	}
	/*for (int i = 0; i < B.size(); i++) {
		cerr << B[i] << " ";
	}
	cerr << endl;*/
	if (A == B) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}