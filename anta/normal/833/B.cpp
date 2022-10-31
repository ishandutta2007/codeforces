#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct AddMaxSegmentTree {
	typedef int Val;
	typedef int Add;
	vector<Val> nodes;
	vector<Val> add;
	int n;
	void init(int minN) {
		n = 1; while (n < minN) n *= 2;
		nodes.assign(n * 2, Val());
		add.assign(n * 2, Val());
	}
	Val getRange(int i, int j) {
		if (i >= j) return Val();
		return getRangeRec(1, i, j, 0, n);
	}
	void addToRange(int i, int j, Add a) {
		if (i < j) addToRangeRec(1, i, j, a, 0, n);
	}
	Val getRangeRec(int i, int qL, int qR, int L, int R) {
		Val a = add[i];
		if (qL <= L && R <= qR)
			return nodes[i] + a;
		if (a != 0) {
			add[i * 2] += a;
			add[i * 2 + 1] += a;
			nodes[i] += a;
			add[i] = 0;
		}
		int mid = (L + R) >> 1;
		Val r = Val();
		if (qL < mid) amax(r, getRangeRec(i * 2 + 0, qL, qR, L, mid));
		if (mid < qR) amax(r, getRangeRec(i * 2 + 1, qL, qR, mid, R));
		nodes[i] = max(nodes[i * 2] + add[i * 2], nodes[i * 2 + 1] + add[i * 2 + 1]);
		return r;
	}
	void addToRangeRec(int i, int qL, int qR, Add a, int L, int R) {
		if (qL <= L && R <= qR) {
			add[i] += a;
			return;
		}
		int mid = (L + R) >> 1;
		if (qL < mid) addToRangeRec(i * 2 + 0, qL, qR, a, L, mid);
		if (mid < qR) addToRangeRec(i * 2 + 1, qL, qR, a, mid, R);
		nodes[i] = max(nodes[i * 2] + add[i * 2], nodes[i * 2 + 1] + add[i * 2 + 1]);
	}
};

int main() {
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> prev(n + 1, -1);
		vector<int> Ls(n);
		rep(i, n) {
			int x = a[i];
			Ls[i] = prev[x];
			prev[x] = i;
		}
		AddMaxSegmentTree segt;
		vector<int> dp, ndp(n + 1, -1);
		ndp[0] = 0;
		rep(kk, k) {
			dp.swap(ndp);
			segt.init(n + 1);
			ndp.assign(n + 1, -1);
			rep(i, n) {
				int x = dp[i];
				if (x != -1)
					segt.addToRange(i, i + 1, x);
				segt.addToRange(Ls[i] + 1, i + 1, 1);
				ndp[i + 1] = segt.getRange(0, i + 1);
			}
		}
		int ans = ndp[n];
		printf("%d\n", ans);
	}
	return 0;
}