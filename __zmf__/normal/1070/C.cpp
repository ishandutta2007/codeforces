// Problem: C. Cloud Computing
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// Author: RedreamMer
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LL long long
#define PB push_back
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e6;
const int M = 100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
	int x = 0, y = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
	for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
	return (y ? -x : x);
}

int a, b, c;
struct pii {
	int x, y;
};
struct seg {
	int w, siz;
} s[N * 4 + 5];
vector<pii> st[N + 5];

#define ls n << 1
#define rs n << 1 | 1
void ins(int n, int l, int r, int k, int p) {
	if(l == r) {
		s[n].w += k * p;
		s[n].siz += p;
		return;
	}
	int mid = (l + r) >> 1;
	if(k <= mid) ins(ls, l, mid, k, p);
	else ins(rs, mid + 1, r, k, p);
	s[n].w = s[ls].w + s[rs].w;
	s[n].siz = s[ls].siz + s[rs].siz;
}
int ask(int n, int l, int r, int k) {
	if(l == r) return l * k;
	int mid = (l + r) >> 1;
	if(s[ls].siz >= k) return ask(ls, l, mid, k);
	else return s[ls].w + ask(rs, mid + 1, r, k - s[ls].siz);
}

signed main() {
	// freopen("in1.in", "r", stdin);
	a = read();
	b = read();
	c = read();
	int x, y, z, w;
	rep(i, 1, c) {
		x = read();
		y = read();
		z = read();
		w = read();
		st[x].PB((pii) {z, w});
		st[y + 1].PB((pii) {-z, w});
	}
	int ans = 0;
	rep(i, 1, a) {
		rep(j, 0, siz(st[i]) - 1) {
			ins(1, 1, N, st[i][j].y, st[i][j].x);
			// cout << st[i][j].x << endl;
		}
		ans += ask(1, 1, N, min(s[1].siz, b));
	}
	cout << ans;
	return 0;
}