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
vector<int> ansA;
vector<int> ansB;
vector<int> ansC;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > A(N);
	vector<int> B(N);
	int res = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
		sum += A[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		sum -= B[i];
	}
	if (sum != 0) {
		cout << "NO" << endl;
		return 0;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int tot = 0;
	vector<int> D(N);
	for (int i = 0; i < N; i++) {
		D[i] = B[i] - A[i].first;
		tot += D[i];
		if (tot < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	vector<int> l;
	for (int i = 0; i < N; i++) {
		if (D[i] > 0) {
			l.push_back(i);
		}
		else {
			while (D[i] < 0) {

				int k = l.back();
				int dd = min(D[k], -D[i]);
				D[k] -= dd;
				D[i] += dd;
				ansA.push_back(A[k].second + 1);
				ansB.push_back(A[i].second + 1);
				ansC.push_back(dd);
				if (D[k] == 0) {
					l.pop_back();
				}
			}
		}
	}
	cout << "YES" << endl;
	cout << ansA.size() << endl;
	for (int i = 0; i < ansA.size(); i++) {
		cout << ansA[i] << " " << ansB[i] << " " << ansC[i] << endl;
	}
}