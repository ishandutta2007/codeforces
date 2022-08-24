#include<cstdio>
#include<algorithm>
#include<set>
#define N_ 200100
#define SZ 262144
#define pli pair<long long,double>
#define pii pair<int,int>
using namespace std;
int X[N_ * 2], CX, INF = 2e9;
int n;
set<pii>Set;
struct point {
	int ck, a, b, c;
}w[N_];
struct Tree {
	long long S[SZ + SZ], M[SZ + SZ], K[SZ + SZ];
	void init() {
		for (int i = 0; i < SZ + SZ; i++)K[i] = INF;
	}
	void Put2(int nd, int b, int e, long long x) {
		S[nd] = x * (X[e + 1] - X[b]);
		M[nd] = min(0ll, S[nd]);
		K[nd] = x;
	}
	void Spread(int nd, int b, int e) {
		if (K[nd] == INF)return;
		int m = (b + e) >> 1;
		Put2(nd * 2, b, m, K[nd]);
		Put2(nd * 2 + 1, m + 1, e, K[nd]);
		K[nd] = INF;
	}
	void UDT(int nd) {
		S[nd] = S[nd * 2] + S[nd * 2 + 1];
		M[nd] = min(M[nd * 2], S[nd * 2] + M[nd * 2 + 1]);
	}
	void Put(int nd, int b, int e, int s, int l, long long x) {
		if (s > l)return;
		if (b == s&&e == l) {
			Put2(nd, b, e, x);
			return;
		}
		Spread(nd, b, e);
		int m = (b + e) >> 1;
		if (s <= m)Put(nd * 2, b, m, s, min(m, l), x);
		if (l > m)Put(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	double Go(int nd, int b, int e, long long x) {
		if (b == e) {
			auto it = Set.lower_bound({ e + 1,-INF });
			it--;
			return X[b] + ((double)-x / it->second);
		}
		Spread(nd, b, e);
		int m = (b + e) >> 1;
		if (M[nd * 2] + x <= 0) {
			return Go(nd * 2, b, m, x);
		}
		else {
			return Go(nd * 2 + 1, m + 1, e, x + S[nd * 2]);
		}
	}
	pli Calc(int nd, int b, int e, int s, int l, long long x) {
		int m = (b + e) >> 1;
		if (b == s && e == l) {
			if (M[nd] + x <= 0) {
				return { S[nd], Go(nd, b, e, x) };
			}
			return { S[nd], -1.0 };
		}
		Spread(nd, b, e);
		long long ss = 0;
		if (s <= m) {
			pli t = Calc(nd * 2, b, m, s, min(m, l), x);
			if (t.second > -0.5)return t;
			ss = t.first;
		}
		if (l > m) {
			pli t = Calc(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x + ss);
			if (t.second > -0.5)return t;
			ss += t.first;
		}
		return { ss,-1.0 };

	}
}T;
void Ins(int t, int c) {
	int x = lower_bound(X, X + CX, t) - X;
	Set.insert({ x,c });
	auto it = Set.find({ x,c });
	auto et = it; et++;
	T.Put(1, 0, CX - 1, x, et->first - 1, c);
}
void Del(int t) {

	int x = lower_bound(X, X + CX, t) - X;
	auto it = Set.lower_bound({ x,-INF });
	auto bt = it; bt--;
	auto et = it; et++;
	Set.erase(it);
	T.Put(1, 0, CX - 1, bt->first, et->first - 1, bt->second);

}
int main() {
	int i, ck, a = 0, b = 0, c = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &ck);
		if (ck == 1) {
			scanf("%d%d", &a, &b);
			X[CX++] = a;
		}
		if (ck == 2) {
			scanf("%d", &a);
		}
		if (ck == 3) {
			scanf("%d%d%d", &a, &b, &c);
			X[CX++] = a;
			X[CX++] = b;
		}
		w[i] = { ck,a,b,c };
	}
	X[CX++] = 0;
	X[CX++] = 2e9;
	sort(X, X + CX);
	CX = unique(X, X + CX) - X;
	CX--;
	T.init();
	Set.insert({ 0,0 });
	Set.insert({ CX,0 });
	for (i = 1; i <= n; i++) {
		if (w[i].ck == 1) {
			Ins(w[i].a, w[i].b);
		}
		if (w[i].ck == 2) {
			Del(w[i].a);
		}
		if (w[i].ck == 3) {
			int b = lower_bound(X, X + CX, w[i].a) - X;
			int e = lower_bound(X, X + CX, w[i].b) - X;
			if (w[i].c == 0) {
				printf("%d\n", w[i].a);
				continue;
			}
			if (b == e) {
				printf("-1\n");
				continue;
			}
			auto it = Set.lower_bound({ b,-INF });
			pii tp = *it;
			if (tp.first != b) {
				Ins(w[i].a, 0);
			}
			pli tt = T.Calc(1, 0, CX - 1, b, e - 1, w[i].c);
			if (tp.first != b) {
				Del(w[i].a);
			}
			if (tt.second < 0) {
				printf("-1\n");
			}
			else {
				printf("%.10f\n", tt.second);
			}
		}
	}
}