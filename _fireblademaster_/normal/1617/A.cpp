#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
char t[5];
char s[105];
int n, occ[26];

void init() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	memset(occ, 0, sizeof occ);
	for (int i = 1; i <= n; ++i) occ[s[i] - 'a'] += 1;
}

string ans = "";
void append(int x) {
	for (int i = 1; i <= occ[x]; ++i) ans += (char)('a' + x);
}

void solve() {
	ans = "";
	if (t[1] == 'a' && t[2] == 'b' && t[3] == 'c' && occ[0] && occ[2] && occ[1]) {
		append(0); append(2); append(1);
		for (int i = 3; i < 26; ++i) append(i);
	} else {
		for (int i = 0; i < 26; ++i) append(i);
	}
	printf("%s\n", ans.c_str());
}

int main() {
	//setIO("");
	int t; scanf("%d", &t); while (t--) {
		init();
		solve();
	}
	return 0;
}