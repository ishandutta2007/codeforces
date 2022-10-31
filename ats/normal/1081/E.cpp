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
	vector<int> A(N / 2);
	
	for (int i = 0; i < N / 2; i++) {
		cin >> A[i];
	}
	vector<vector<int> > soinsu(200010);
	for (int i = 2; i < 200005; i++) {
		if (soinsu[i].size() == 0) {
			for (int j = i; j < 200005; j += i) {
				soinsu[j].push_back(i);
			}
		}
	}
	vector<vector<int> > yakusuu(N/2);
	for (int i = 0; i < N/2; i++) {
		int t = A[i];
		yakusuu[i].push_back(1);
		int pr = 1;
		for (int j : soinsu[A[i]]) {
			int sz = yakusuu[i].size();
			pr = 1;
			while (t % j == 0) {
				pr *= j;
				t /= j;
				for (int k = 0; k < sz; k++) {
					yakusuu[i].push_back(yakusuu[i][k] * pr);
				}
			}
		}
	}


	vector<int> res(N);
	int sum = 0;
	int y;
	int a, b;
	int INF = (int)1 << 60;
	for (int i = 0; i < N / 2; i++) {
		int minb = INF;
		int mina;
		for (auto x : yakusuu[i]) {
			y = A[i] / x;
			if (x < y)continue;
			if ((x + y) % 2)continue;
			a = (x + y) / 2;
			b = x - a;
			if (b > sum) {
				if (minb > b) {
					minb = b;
					mina = a;
				}
			}
		}
		if (minb == INF) {
			cout << "No" << endl;
			return 0;
		}
		res[2 * i] = minb*minb;
		res[2 * i + 1] = mina*mina;
		sum = mina;
	}
	for (int i = N - 1; i > 0; i--) {
		res[i] = res[i] - res[i - 1];
	}
	cout << "Yes" << endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}