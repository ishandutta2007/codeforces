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

struct Q {
	char t;
	int x;
	int y;
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Q> A(N);
	vector<string> res;
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> A[i].t >> A[i].x >> A[i].y;
		if (A[i].x > A[i].y) {
			swap(A[i].x, A[i].y);
		}
		st.insert(A[i].x);
		st.insert(A[i].y);
	}
	map<int, int> mp;
	int x = 0;
	for (int s : st) {
		mp[s] = x;
		x++;
	}
	for (int i = 0; i < N; i++) {
		A[i].x = mp[A[i].x];
		A[i].y = mp[A[i].y];
	}
	vector<int> T(x, (int)1 << 60);
	int mxx = 0;
	int mxy = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].t == '+') {
			mxx = max(mxx, A[i].x);
			mxy = max(mxy, A[i].y);
		}
		else {
			if (A[i].x >= mxx && A[i].y >= mxy) {
				res.push_back("YES");
			}
			else {
				res.push_back("NO");
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
}