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

enum { DUMMY, IN, NOT, AND, OR, XOR } type[(int)1e6];
int lhs[(int)1e6];
int rhs[(int)1e6];
int sz[(int)1e6];
bool initVal[(int)1e6];

void build(int u) {
	if (type[u] == IN) {
		sz[u] = 1;
	}
	else if (type[u] == NOT) {
		build(lhs[u]);
		sz[u] = sz[lhs[u]];
		initVal[u] = !initVal[lhs[u]];
	}
	else {
		build(lhs[u]), build(rhs[u]);
		sz[u] = sz[lhs[u]] + sz[rhs[u]];
		initVal[u] =
			type[u] == AND ? initVal[lhs[u]] && initVal[rhs[u]] :
			type[u] == XOR ? initVal[lhs[u]] ^ initVal[rhs[u]] :
			type[u] == OR ? initVal[lhs[u]] || initVal[rhs[u]] :
			(assert(false), 0);
	}
}

void f(int u, bool flip, bool fix) {
	if (type[u] == IN) {
		lhs[u] = fix ? flip : !initVal[u] ^ flip;
	}
	else if (type[u] == NOT) {
		f(lhs[u], fix ? flip : !flip, fix);
	}
	else if (fix) {
		f(lhs[u], flip, true);
		f(rhs[u], flip, true);
	}
	else if (type[u] == XOR) {
		f(lhs[u], flip ^ initVal[rhs[u]], false);
		f(rhs[u], flip ^ initVal[lhs[u]], false);
	}
	else if (type[u] == AND) {
		if (initVal[rhs[u]])
			f(lhs[u], flip, false);
		else
			f(lhs[u], flip, true);

		if (initVal[lhs[u]])
			f(rhs[u], flip, false);
		else
			f(rhs[u], flip, true);
	}
	else if (type[u] == OR) {
		if (initVal[rhs[u]])
			f(lhs[u], flip ^ 1, true);
		else
			f(lhs[u], flip, false);

		if (initVal[lhs[u]])
			f(rhs[u], flip ^ 1, true);
		else
			f(rhs[u], flip, false);
	}
	else
		assert(false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		type[i] = s == "IN" ? IN : s == "NOT" ? NOT : s == "XOR" ? XOR : s == "AND" ? AND : s == "OR" ? OR : (assert(false), XOR);
		if (type[i] == IN)
			cin >> initVal[i];
		else if (type[i] == NOT)
			cin >> lhs[i];
		else {
			cin >> lhs[i] >> rhs[i];
			if (lhs[i] > rhs[i])
				swap(lhs[i], rhs[i]);
		}
		--lhs[i], --rhs[i];
	}
	build(0);
	f(0, false, false);
	for (int i = 0; i < n; ++i)
		if (type[i] == IN)
			cout << lhs[i];
	return 0;
}