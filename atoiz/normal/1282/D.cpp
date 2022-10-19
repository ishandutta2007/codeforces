/*input

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

int ask(string str)
{
	cout << str << endl;
	int x;
	cin >> x;
	return x;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = ask("a");
	if (!n) return 0;

	int cur = ask(string(n, 'b'));
	if (!cur) return 0;

	++n;

	string str(n, 'b');
	FOR(i, 0, n - 1) {
		str[i] = 'a';
		int nxt = ask(str);
		if (!nxt) return 0;
		if (nxt >= cur) str[i] = 'b';
		else cur = nxt;
	}
	assert(0);

	return 0;
}