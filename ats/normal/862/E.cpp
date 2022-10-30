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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> A(N);
	vector<int> B(M);
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	int sum = 0;
	for (int i = 0; i < M; i++) {
		if (i >= N) {
			if ((i - N) % 2 == 0) {
				sum += B[i - N];
			}
			else {
				sum -= B[i - N];
			}
		}
		if (i % 2 == 0) {
			sum -= B[i];
		}
		else {
			sum += B[i];
		}
		if (i >= N - 1) {
			if ((i - N + 1) % 2 == 0) {
				vec.push_back(sum);
			}
			else {
				vec.push_back(-sum);
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		//cerr << vec[i] << endl;
	}
	sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	sum = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			sum += A[i];
		}
		else {
			sum -= A[i];
		}
	}
	int l, r, x;
	vector<int> res;
	for (int i = 0; i <= Q; i++) {
		if (i > 0) {
			cin >> l >> r >> x;
			l--;
			r--;
			if ((r - l) % 2 == 0) {
				if (l % 2 == 0) {
					sum += x;
				}
				else {
					sum -= x;
				}
			}
		}
		//cerr <<i<<" "<< sum << endl;
		auto xx = lower_bound(vec.begin(), vec.end(), -sum);
		xx--;
		
		r = abs(sum + (*xx));
		xx++;
		if (xx != vec.end()) {
			r = min(r, abs(sum + (*xx)));
		}
		res.push_back(r);
	}
	for (int i = 0; i <= Q; i++) {
		cout << res[i] << endl;
	}
}