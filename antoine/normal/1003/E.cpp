#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int N, D, K;
bool possible = true;
vector<pair<int, int>> edges;

void f(int deg, int len, int parent, int &currID) {
	assert(len > 0);
	if (edges.size() >= N - 1) return;
	int myID = currID++;
	edges.emplace_back(parent, myID);
	if(len - 1 > 0)
		while (deg-- > 0 && edges.size() < N - 1)
			f(K - 1, len - 1, myID, currID);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> D >> K;

	if (N < D + 1) {
		cout << "NO";
		return 0;
	}

	if (K == 1) {
		if (D == 1 && N == 2)
			cout << "YES\n1 2";
		else
			cout << "NO";
		return 0;
	}

	for (int i = 1; i <= D; ++i)
		edges.emplace_back(i, i + 1);

	int currID = D + 2;
	for (int i = 2; i <= D && edges.size() < N - 1; ++i) {
		for (int j = 0; j < K - 2 && edges.size() < N - 1; ++j)
			f(K - 1, min(i - 1, D + 1 - i), i, currID);
	}

	assert(edges.size() <= N - 1);
	if (edges.size() != N - 1) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (auto &&e : edges)
		cout << e.first << ' ' << e.second << '\n';
	return 0;
}