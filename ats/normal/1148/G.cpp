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
bool B[10000001];
bool X[10000001];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		X[A[i]] = true;
	}
	vector<vector<int> > ps(10000001);

	for (int i = 2; i <= 10000000; i++) {
		if (!B[i]) {
			if (X[i]) {
				ps[i].push_back(i);
			}
			for (int j = i + i; j <= 10000000; j += i) {
				if (X[j]) {
					ps[j].push_back(i);
				}
				B[j] = true;
			}
		}
	}
	map<int, vector<int> > mp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < ps[A[i]].size(); j++) {
			mp[ps[A[i]][j]].push_back(i);
		}
	}
	vector<int> res;
	vector<pair<int, int> > cnt(N);
	for (int i = 0; i < N; i++) {
		cnt[i].first = 0;
		cnt[i].second = i;
	}
	for (auto m : mp) {
		if ((int)m.second.size() >= K) {
			for (int i = 0; i < K; i++) {
				res.push_back(m.second[i] + 1);
			}
			break;
		}
		else {
			for (int i = 0; i < m.second.size(); i++) {
				cnt[m.second[i]].first += m.second.size();
			}
		}


	}
	if (res.size() == 0) {
		sort(cnt.begin(), cnt.end());
		for (int i = 0; i < K; i++) {
			res.push_back(cnt[i].second + 1);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i] ;
	}
	cout << endl;

}