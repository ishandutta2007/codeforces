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
	int N, P;
	cin >> N >> P;
	set<pair<int, int> > st;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		st.emplace(A[i], i);
	}
	vector<int> res(N);
	int e = 1;
	set<int> qs;
	int cur = 0;
	queue<int> qu;
	vector<int> X(N, 0);
	set<int> kuu;
	while (st.size()) {
		auto p = st.begin();
		int a = (*p).first;
		int b = (*p).second;

		st.erase(p);
		if (b >= N) {
			e = 1;
			cur = a;
			kuu.erase(b - N);
			if (qs.size() > 0) {
				int t = *qs.begin();
				if (kuu.size() == 0 || (*kuu.begin() > t)) {
					qu.push(t);
					qs.erase(t);
					kuu.insert(t);
				}
			}
		}
		else {
			qs.insert(b);
			cur = a;
			int t = *qs.begin();
			if (kuu.size() == 0 || (*kuu.begin() > t)) {
				qu.push(t);
				qs.erase(t);
				kuu.insert(t);
			}
		}
		if (e == 1 && qu.size()) {
			int x = qu.front();
			qu.pop();
			res[x] = cur + P;
			st.emplace(cur + P, N + x);
			e = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}