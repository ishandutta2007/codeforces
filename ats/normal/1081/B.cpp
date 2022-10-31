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
	vector<int> res(N);
	map<int, vector<int> > mp;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mp[A[i]].push_back(i);
	}
	int t = 1;
	for (auto &x : mp) {
		int a = N - (int)x.first;
		//cerr << a << endl;
		while ((int)x.second.size() > 0) {
			for (int i = 0; i < a; i++) {
				if (x.second.size() == 0) {
					cout << "Impossible" << endl;
					return  0;
				}
				res[x.second.back()] = t;
				x.second.pop_back();
			}
			t++;
		}
	}
	cout << "Possible" << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}