#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M;
map <int, int> A, B;
vector <int> V;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		V.push_back(x);
		A[x]++;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x; scanf("%d", &x);
		V.push_back(x);
		B[x]++;
	}
}

void solve() {
	sort(V.begin(), V.end());
	V.resize(unique(V.begin(), V.end()) - V.begin());
	int cntA = 0, cntB = 0;
	int bestA = 0, bestB = 0, maks = -3 * M;
	for (int i = 0; i <= V.size(); i++) {
		int currA = 3 * N - cntA;
		int currB = 3 * M - cntB;
		int curr = currA - currB;
		if (i < V.size()) {
			cntA += A[V[i]];
			cntB += B[V[i]];
		}
		if (curr < maks) continue;
		if (curr == maks && currA < bestA) continue;
		maks = curr;
		bestA = currA;
		bestB = currB;
	}
	printf("%d:%d\n", bestA, bestB);
}

int main() {
	load();
	solve();
	return 0;
}