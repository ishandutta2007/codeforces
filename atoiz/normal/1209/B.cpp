/*input
6
011100
5 3
5 5
2 4
3 5
4 2
1 5

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

const int MAXN = 50000;
int cnt[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string str; cin >> str;
	FOR(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		bool on = str[i] == '1';
		FOR(j, 0, MAXN - 1) {
			if (j >= b && (j - b) % a == 0) on = !on;
			if (on) ++cnt[j];
		}
	}
	cout << *max_element(cnt, cnt + MAXN) << endl;

	return 0;
}