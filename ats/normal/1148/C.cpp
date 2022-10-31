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
	vector < pair<int, int> > vp(N);
	vector<int> pos(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i]--;
		pos[A[i]] = i;
		vp[i].first = abs((N / 2) - i);
		vp[i].second = i;
	}

	sort(vp.begin(), vp.end());
	vector<pair<int, int> > res;
	for (int i = 0; i < N;) {
		int p = vp[i].second;
		if (A[p] == p) i++;
		else {

			if (2 * abs(pos[p] - p) >= N) {
				int ap = p;
				res.emplace_back(ap + 1, pos[p] + 1);
				int b = A[ap];
				swap(A[pos[p]], A[ap]);
				swap(pos[p], pos[b]);
			}
			else if (2 * abs(pos[p] - 0) >= N) {
				int ap = 0;
				res.emplace_back(ap + 1, pos[p] + 1);
				int b = A[ap];
				swap(A[pos[p]], A[ap]);
				swap(pos[p], pos[b]);
			}
			else if (2 * abs(pos[p] - (N - 1)) >= N) {
				int ap = N - 1;
				res.emplace_back(ap + 1, pos[p] + 1);
				int b = A[ap];
				swap(A[pos[p]], A[ap]);
				swap(pos[p], pos[b]);
			}



		}

	}
	/*for (int i = 0; i < N; i++) {
		cerr << A[i] << " ";
	}
	cerr << endl;*/
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
}