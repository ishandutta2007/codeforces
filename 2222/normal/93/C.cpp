#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int v[26], n;
int best = 10, r[26];
set<ll> H;

bool was(int i) {
	vi q(v, v + i + 1);
	UN(q);
	ll hsh = 0;
	for (int x : q) hsh = hsh * 1000000007 + x;
	if (H.count(hsh)) return true;
	H.insert(hsh);
	return false;
}

void go(int i) {
	if (i >= best || v[i] > n) return;
	if (was(i)) return;
	if (v[i] == n) {
		best = i;
		memcpy(r, v, (i + 1) * sizeof(int));
		return;
	}
	++i;
	REP (j, i) {
		for (int k = 1; k <= 8; k *= 2) {
			v[i] = v[j] * k;
			if (k > 1) go(i);
			REP (l, i) {
				v[i] += v[l];
				go(i);
				v[i] -= v[l];
			}
		}
	}
}

void restore(int i) {
	printf("lea e%cx, ", char('a' + i));
	REP (j, i) {
		for (int k = 1; k <= 8; k *= 2) {
			int x = r[j] * k;
			if (k > 1 && x == r[i]) {
				printf("[%d*e%cx]\n", k, char('a' + j));
				return;
			}
			REP (l, i) {
				x += r[l];
				if (x == r[i]) {
					if (k > 1) {
						printf("[e%cx + %d*e%cx]\n", char('a' + l), k, char('a' + j));
						return;
					}
					printf("[e%cx + e%cx]\n", char('a' + l), char('a' + j));
					return;
				}
				x -= r[l];
			}
		}
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	v[0] = 1;
	go(0);
	cout << best << endl;
	for (int i = 1; i <= best; ++i)
		restore(i);
	return 0;
	//map<vi, vi> P;
//	queue<vi> Q;
//	Q.push({1});
//	P[Q.front()] = {};
//	for (int st = 0; ; ++st) {
//		vi v = Q.front(); Q.pop();
//		if (binary_search(all(v), n)) {
//			cout << st << endl;
//			return 0;
//		}
//		for (int x : v) {
//			for (int k = 2; k <= 8; k *= 2) {
//				vi u = v;
//				u.pb(x * k);
//				UN(u);
//				if (P.count(u) == 0) {
//					P[u] = v;
//					Q.push(u);
//				}
//			}
//		}
//		for (int y : v) for (int x : v) {
//			for (int k = 1; k <= 8; k *= 2) {
//				vi u = v;
//				u.pb(x + y * k);
//				UN(u);
//				if (P.count(u) == 0) {
//					P[u] = v;
//					Q.push(u);
//				}
//			}
//		}
//	}
}