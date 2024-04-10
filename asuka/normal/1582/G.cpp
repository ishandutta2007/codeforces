#include<bits/stdc++.h>
#define ll long long
#define N 1000123
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
using namespace std;
bool notp[N];
int pri[N], tot, low[N];
void getPri() {
	rep(i, 2, 1000000) {
		if (!notp[i]) pri[++tot] = i, low[i] = i;
		for (int j = 1; j <= tot && pri[j] * i <= 1000000; ++j) {
			notp[i * pri[j]] = 1;
			low[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int n, a[N];
char b[N];
vector<pii> num[N], event[N];
int r[N], sum[N], q[N], head, tail;
multiset<int> S;
void solve(vector<pii> &vec) {
	int m = SZ(vec);
	head = 1;
	tail = 0;
	// rep(i, 1, m) printf("(%d %d) ", vec[i - 1].fi, vec[i - 1].se);
	// printf("\n");
	rep(i, 1, m) r[i] = -1;
	rep(i, 1, m + 1) sum[i] = 0;
	per(i, 1, m) sum[i] = sum[i + 1] + vec[i - 1].fi;
	rep(i, 1, m + 1) {
		while (head <= tail && sum[q[tail]] < sum[i]) r[q[tail--]] = i;
		q[++tail] = i;
	}
	// rep(i, 1, m) printf("%d ", r[i]);
	// printf("\n");
	int lst = 0;
	rep(i, 1, m) {
		int pos = r[i] == -1 ? n + 1 : vec[r[i] - 2].se;
		pos--;
		// [lst + 1, vec[i - 1].se] <= pos
		// printf("[%d, %d] <= %d\n", lst + 1, vec[i - 1].se, pos);
		event[lst + 1].emplace_back(1, pos);
		event[(vec[i - 1].se + 1)].emplace_back(-1, pos);
		lst = vec[i - 1].se;
	}
}
int read() {
	int s = 0, w = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int main() {
	//freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	clock_t st = clock();
	getPri();
	scanf("%d", &n);
	rep(i, 1, n) a[i] = read();
	scanf("%s", b + 1);
	rep(i, 1, n) {
		int x = a[i];
		while (x > 1) {
			int u = low[x], c = 0;
			while (x % u == 0) x /= u, c++;
			num[u].emplace_back((b[i] == '*' ? 1 : -1) * c, i);
		}
	}
	rep(_, 1, tot) if (SZ(num[pri[_]])) solve(num[pri[_]]);
	ll ans = 0;
	rep(i, 1, n) {
		for(auto x : event[i]) {
			if(x.fi == 1) S.insert(x.se);
			else S.erase(S.find(x.se));
		}
		int rr = SZ(S) == 0 ? n : *S.begin();
		ans += max(0, rr - i + 1);
	}
	printf("%lld\n", ans);
	cerr << (1.0 * clock() - st) / CLOCKS_PER_SEC << endl;
	return 0;
}