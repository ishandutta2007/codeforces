/*input
6
1 2 4 5 6 3
*/

// https://codeforces.com/contest/1290/submission/70474000

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 150007, INF = 1e8 + 9;

void minimize(int &x, int y) { x = (x < y ? x : y); }

int N;
int A[MAXN];

int bit[MAXN];
void inc(int i)
{ 
	for (; i <= N; i += i & (-i)) ++bit[i]; 
}

int get(int i)
{
	int ans = 0;
	for (; i > 0; i -= i & (-i)) ans += bit[i];
	return ans;
}

int cnt[MAXN << 2], fir[MAXN << 2], sec[MAXN << 2], tag[MAXN << 2];
int64_t total = 0;
void push(int rt)
{
	if (tag[rt] != INF) {
		minimize(fir[rt << 1], tag[rt]);
		minimize(tag[rt << 1], tag[rt]);
		minimize(fir[rt << 1 | 1], tag[rt]);
		minimize(tag[rt << 1 | 1], tag[rt]);
		tag[rt] = INF;
	}
}

void pull(int rt)
{
	int lc = rt << 1, rc = lc | 1;
	if (fir[lc] == fir[rc]) fir[rt] = fir[lc], cnt[rt] = cnt[lc] + cnt[rc], sec[rt] = max(sec[lc], sec[rc]);
	else if (fir[lc] < fir[rc]) fir[rt] = fir[rc], cnt[rt] = cnt[rc], sec[rt] = max(fir[lc], sec[rc]);
	else fir[rt] = fir[lc], cnt[rt] = cnt[lc], sec[rt] = max(sec[lc], fir[rc]);
}

void add(int i, int x, int rt = 1, int lo = 1, int hi = N)
{
	if (lo == hi) {
		cnt[rt] = 1, fir[rt] = x;
		return;
	}

	int md = (lo + hi) >> 1;
	push(rt);
	i <= md ? add(i, x, rt << 1, lo, md) : add(i, x, rt << 1 | 1, md + 1, hi);
	pull(rt);
}

void updMin(int l, int r, int x, int rt = 1, int lo = 1, int hi = N)
{
	if (hi < l || r < lo || fir[rt] <= x) return;
	if (l <= lo && hi <= r && sec[rt] < x) {
		total -= (int64_t) cnt[rt] * get(fir[rt]);
		fir[rt] = tag[rt] = x;
		total += (int64_t) cnt[rt] * get(fir[rt]);
		return;
	} 

	int md = (lo + hi) >> 1;
	push(rt);
	updMin(l, r, x, rt << 1, lo, md);
	updMin(l, r, x, rt << 1 | 1, md + 1, hi);
	pull(rt);
}

void init()
{
	fill_n(bit, N + 1, 0);
	fill_n(cnt, (N + 1) << 2, 0);
	fill_n(fir, (N + 1) << 2, 0);
	fill_n(sec, (N + 1) << 2, 0);
	fill_n(tag, (N + 1) << 2, INF);
	total = 0;
}

int64_t ans[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		A[x] = i;
	}

	for (int _ = 0; _ < 2; ++_) {
		init();
		for (int i = 1; i <= N; ++i) {
			add(A[i], N);
			updMin(1, A[i] - 1, A[i] - 1);
			inc(A[i]);
			total += (2 * i - 1) - get(A[i] - 1);	
			ans[i] += total;

			A[i] = N - A[i] + 1;
		}
	}

	for (int i = 1; i <= N; ++i) printf("%I64d\n", ans[i] - (int64_t) i * i);
}