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
	vector<pair<pair<int, int>, int> > A(N);
	vector<pair<pair<int, int>, int> > B;
	vector<pair<pair<int, int>, int> > C;
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first.first >> A[i].first.second;
		A[i].second = i;
	}
	for (int i = 0; i < N; i++) {
		if (A[i].first.first < A[i].first.second) {
			B.push_back(A[i]);
		}
		else if (A[i].first.first > A[i].first.second) {
			swap(A[i].first.first, A[i].first.second);
			C.push_back(A[i]);
		}
	}
	if ((int)B.size() > (int)C.size()) {
		A = B;
		sort(A.rbegin(), A.rend());
	}
	else {
		A = C;
		sort(A.begin(), A.end());
	}

	
	cout << A.size() << endl;
	for (int i = 0; i < A.size(); i++) {
		if (i > 0)cout << " ";
		cout << A[i].second + 1;
	}
	cout << endl;
}