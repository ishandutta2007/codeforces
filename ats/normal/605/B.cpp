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
struct Edge {
	int w;
	int t;
	int idx;
	int a, b;
	bool operator<(const Edge &right) const {
		return (w == right.w) ? (t > right.t) : (w < right.w);
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<Edge> es(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> es[i].w >> es[i].t;
		es[i].idx = i;
	}

	sort(es.begin(), es.end());

	int c = 0;
	int B = 2;
	int A = 0;
	for (int i = 0; i < M; i++) {
		if (es[i].t == 1) {
			es[i].a = c;
			es[i].b = c + 1;
			c++;
		}
		else {

			if (B > c) {
				cout << -1 << endl;
				return 0;
			}
			es[i].a = A;
			es[i].b = B;

			A++;

			if (A == B - 1) {
				B++;
				A = 0;
			}
		}
	}

	vector<pair<int, int> > vp(M);
	for (int i = 0; i < M; i++) {
		vp[es[i].idx].first = es[i].a + 1;
		vp[es[i].idx].second = es[i].b + 1;
	}
	for (int i = 0; i < M; i++) {
		cout << vp[i].first << " " << vp[i].second << endl;
	}
}