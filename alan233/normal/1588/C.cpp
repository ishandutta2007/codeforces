// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 300005;

ll a[N], s[N];
ll stk[2][N], ans;
int top[2], n;

map<ll, tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>> mp[2];

int calc(ll *a, int n, ll x) {
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (s[a[mid]] < x) l = mid;
		else r = mid - 1;
	}
	return a[l];
}

void solve() {
	top[0] = top[1] = ans = 0;
	mp[0].clear(), mp[1].clear();
	n = read();
	stk[0][0] = stk[1][0] = n;
	rep(i, 1, n) a[i] = read(), s[i] = a[i] - s[i - 1];
	int now = ~n & 1;
	per(i, n, 1) {
		now ^= 1;
		while (top[now] && s[i] <= s[stk[now][top[now]]]) top[now]--;
		stk[now][++top[now]] = i;
		mp[now][s[i]].insert(i);
		int p1 = calc(stk[now ^ 1], top[now ^ 1], s[i - 1]);
		int p2 = calc(stk[now], top[now], -s[i - 1]);
		ans += mp[now ^ 1][s[i - 1]].order_of_key(min(p1, p2) + 1) + 
		       mp[now][-s[i - 1]].order_of_key(min(p1, p2) + 1);
	}
	print(ans, '\n');
}

int main() {
	int T = read();
	while (T--) {
		solve();
	}
	return 0;
}