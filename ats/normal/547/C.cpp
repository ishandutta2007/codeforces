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

int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> res(Q + 1, 0);
	int a;
	vector<int> V(N, -1);
	int num = 0;
	vector<vector<int> > soinsu(500010);
	for (int i = 2; i < 500005; i++) {
		if (soinsu[i].size() == 0) {
			for (int j = i; j < 500005; j += i) {
				soinsu[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		auto &t = soinsu[A[i]];
		A[i] = 1;
		for (int j = 0; j < t.size(); j++) {
			A[i] *= t[j];
		}
		//cerr << i << " " << A[i] << endl;
	}
	vector<vector<int> > yakusuu(N);
	for (int i = 0; i < N; i++) {
		int t = A[i];
		yakusuu[i].push_back(1);
		int pr = 1;
		for (int j : soinsu[A[i]]) {
			int sz = yakusuu[i].size();
			pr = 1;
			while (t % j == 0){
				pr *= j;
				t /= j;
				for (int k = 0; k < sz; k++) {
					yakusuu[i].push_back(yakusuu[i][k] * pr);
				}
			}
		}
	}
	//for (int i = 0; i < N; i++) {
	//	cerr << A[i] << " ";
	//	for (int j = 0; j < yakusuu[i].size(); j++) {
	//		cerr << yakusuu[i][j] << " ";
	//	}
	//	cerr << endl;
	//}
	vector<int> cnt(500010, 0);
	for (int i = 0; i < Q; i++) {
		cin >> a; a--;
		if (V[a] == -1) {
			int diff = num;
			for (auto y : yakusuu[a]) {
				if (y != 1) {
					if (soinsu[y].size() % 2 == 0) {
						diff += cnt[y];
					}
					else {
						diff -= cnt[y];
					}
				}
			}
			res[i + 1] = res[i] + diff;
			for (auto y : yakusuu[a]) {
				cnt[y]++;
			}
			num++;
			V[a] = i;
		}
		else {
			num--;
			for (auto y : yakusuu[a]) {
				cnt[y]--;
			}

			int diff = num;
			for (auto y : yakusuu[a]) {
				if (y != 1) {
					if (soinsu[y].size() % 2 == 0) {
						diff += cnt[y];
					}
					else {
						diff -= cnt[y];
					}
				}
			}
			res[i + 1] = res[i] - diff;
			V[a] = -1;
		}
	}
	for (int i = 1; i <= Q; i++) {
		cout << res[i] << endl;
	}
}