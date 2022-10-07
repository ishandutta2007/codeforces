#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
#define INF 0x3f3f3f3f
int n, w, len[N], tp, sta[N], l[N], r[N], mx[N];
std :: vector<int> a[N];
std :: vector< std :: pair<int, int> > p[N];
int main(){
	n = read(), w = read();
	for (register int i = 1; i <= n; ++i){
		len[i] = read(), a[i].push_back(0);
		for (register int j = 1; j <= len[i]; ++j) a[i].push_back(read());
		a[i].push_back(0);
	}
	for (register int i = 1; i <= n; ++i){
		tp = 0;
		for (register int j = 0; j <= len[i] + 1; ++j){
			while (tp > 0 && a[i][sta[tp]] < a[i][j]) --tp;
			if (tp == 0) l[j] = -INF; else l[j] = sta[tp];
			sta[++tp] = j;
		}
		tp = 0;
		for (register int j = len[i] + 1; j >= 0; --j){
			while (tp > 0 && a[i][sta[tp]] < a[i][j]) --tp;
			if (tp == 0) r[j] = INF; else r[j] = sta[tp];
			sta[++tp] = j;
		}
		for (register int j = 0; j <= len[i] + 1; ++j){
			int L = std :: max(j, l[j] + w - len[i] + 1), R = std :: min(j + w - len[i], r[j] - 1);
			L = std :: max(L, 1), R = std :: min(R, w);
			if (L <= R) p[L].push_back(std :: make_pair(i, a[i][j]));
		}
	}
	long long sum = 0;
	for (register int i = 1; i <= w; ++i){
		for (auto t : p[i]) sum -= mx[t.first], sum += mx[t.first] = t.second;
		printf("%lld ", sum);
	}
}