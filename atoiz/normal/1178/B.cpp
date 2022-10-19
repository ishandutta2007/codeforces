/*input
vvovooovovvovoovoovvvvovovvvov


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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

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

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string S; cin >> S;
	ll cnt1 = 0, cnt2 = 0, cnt3 = 0;

	FOR(i, 0, SZ(S) - 1) {
		if (i > 0 && S[i - 1] == 'v' && S[i] == 'v') {
			cnt3 += cnt2;
			cnt1 += 1;
		} else if (S[i] == 'o') {
			cnt2 += cnt1;
		}
	}

	cout << cnt3 << endl;

	return 0;
}