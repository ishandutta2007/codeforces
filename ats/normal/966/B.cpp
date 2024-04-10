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
	int s1, s2;
	cin >> s1 >> s2;
	vector < pair<int, int> >vp(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> vp[i].first;
		vp[i].second = i;
	}
	sort(vp.begin(), vp.end());
	vector<int> A1(N), A2(N);

	for (int i = 0; i < N; i++) {
		//cerr << vp[i].first << endl;
		A1[i] = 1 + ((s1 - 1) / vp[i].first);
		A2[i] = 1 + ((s2 - 1) / vp[i].first);
	}
	/*for (int i = 0; i < N; i++) {
		cout << A1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << A2[i] << " ";
	}
	cout << endl;*/
	int a1, a2;
	a1 = a2 = N + 1;
	for (int i = 1; i <= N; i++) {
		if (A1[N - i] <= i) {
			a1 = i;
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (A2[N - i] <= i) {
			a2 = i;
			break;
		}
	}
	if (a1 == N + 1 || a2 == N + 1) {
		cout << "No" << endl;
		return 0;
	}
	//cerr << a1 << " " << a2 << endl;
	vector<int> res1, res2;
	for (int i = 0; i < N; i++) {
		if (i + A1[i] <= N - a2) {
			for (int j = 0; j < A1[i]; j++) {
				res1.push_back(vp[i + j].second + 1);
			}
			for (int j = 0; j < a2; j++) {
				res2.push_back(vp[N - a2 + j].second + 1);
			}
			break;
		}
	}
	if ((int)res1.size() == 0) {
		for (int i = 0; i < N; i++) {
			if (i + A2[i] <= N - a1) {
				for (int j = 0; j < A2[i]; j++) {
					res2.push_back(vp[i + j].second + 1);
				}
				for (int j = 0; j < a1; j++) {
					res1.push_back(vp[N - a1 + j].second + 1);
				}
				break;
			}
		}
	}
	if ((int)res1.size() > 0) {
		cout << "Yes" << endl;
		cout << res1.size() << " " << res2.size() << endl;
		for (int i = 0; i < res1.size(); i++) {
			if (i > 0)cout << " ";
			cout << res1[i];
		}
		cout << endl;
		for (int i = 0; i < res2.size(); i++) {
			if (i > 0)cout << " ";
			cout << res2[i];
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
}