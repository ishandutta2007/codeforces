#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ends ends_

const int P = 998244353, MAXN = 400007, MAXE = 400007;
int A, B, E, M, Q;
int adjXor[MAXE], dsu[MAXE], ends[MAXE][2];
long long groupHash[MAXE][2], sumHash = 0;
int leave[MAXE], curPow = 1;

int getRoot(int e) { return (dsu[e] < 0 ? e : dsu[e] = getRoot(dsu[e])); }
void reversePath(int e) {
	e = getRoot(e);
	if (!(dsu[e] & 1)) {
		sumHash += groupHash[e][1] - groupHash[e][0];
		swap(groupHash[e][0], groupHash[e][1]);
	}
	swap(ends[e][0], ends[e][1]);
}

void join(int lu, int ru) {
	int l = getRoot(lu), r = getRoot(ru);
	if (l == r) return;
	if (dsu[l] > dsu[r]) swap(l, r), swap(lu, ru);
	if (ends[l][1] != lu) reversePath(l);
	if (ends[r][0] != ru) reversePath(r);

	adjXor[lu] ^= ru;
	adjXor[ru] ^= lu;

	if (dsu[l] & 1) {
		sumHash += groupHash[r][1] - groupHash[r][0];
		groupHash[l][0] += groupHash[r][1];
		groupHash[l][1] += groupHash[r][0];
	} else {
		groupHash[l][0] += groupHash[r][0];
		groupHash[l][1] += groupHash[r][1];
	}

	dsu[l] += dsu[r], dsu[r] = l;
	ends[l][1] = ends[r][1];
}

void addEdge(int a, int b) {
	++E, curPow = (curPow << 1) % P;

	dsu[E] = -1, ends[E][0] = ends[E][1] = E;
	groupHash[E][0] = curPow, groupHash[E][1] = 0;
	sumHash += curPow;

	if (leave[a]) {
		join(leave[a], E);
		leave[a] = 0;
	} else {
		leave[a] = E;
	}

	if (leave[b]) {
		join(leave[b], E);
		leave[b] = 0;
	} else {
		leave[b] = E;
	}
}

int main() {
	cin >> A >> B >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		addEdge(a, A + b);
	}
	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			addEdge(a, A + b);
			cout << int(sumHash % P) << endl;
		} else {
			vector<int> vec;
			for (int r = 1; r <= E; ++r) {
				if (getRoot(r) != r) continue;
				int x = ends[r][0], y = adjXor[x]; 
				while (x) {
					vec.push_back(x);
					if (!y) break;
					x ^= adjXor[y];
					y ^= adjXor[x];
				}
			}
			cout << vec.size();
			for (int e : vec) cout << ' ' << e;
			cout << endl;
		}
	}
}