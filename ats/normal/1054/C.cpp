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
	vector<int> L(N);
	vector<int> R(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> R[i];
	}
	map<int, vector<int> > mp;
	for (int i = 0; i < N; i++) {
		mp[-L[i] - R[i]].push_back(i);
	}
	int cur = 1;
	vector<int> res(N);
	for (auto m : mp) {
		for (auto i : m.second) {
			res[i] = cur;
		}
		cur++;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (res[i] < res[j]) {
				L[i]--;
			}
		}
		for (int j = i + 1; j < N; j++) {
			if (res[i] < res[j]) {
				R[i]--;
			}
		}
		if (L[i] != 0 || R[i] != 0) {
			cout << "NO" << endl;
			return  0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
}