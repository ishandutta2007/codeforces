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
constexpr int N = 100005;
int n, m = 0;
int a[N];
void init() {
	scanf("%d", &n);
	vector<int> used(n + 1, 0), vec;
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		if (x > n || used[x]) vec.push_back(x);
		else used[x] = 1;
	}
	sort(vec.begin(), vec.end());
	int pos = 0, err = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		int num = vec[pos++];
		if (i <= (num - 1) / 2) ++ans;
		else {
			err = 1; 
			break;
		}
	}
	if (err) printf("-1\n");
	else printf("%d\n", ans);
}

void solve() {
}

int main() {
	//setIO("");
	int t; scanf("%d", &t); while (t--) {
		init();
		solve();
	}
	return 0;
}