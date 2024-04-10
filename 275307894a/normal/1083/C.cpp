#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = N << 1;
vector<int> S[N];
int n, m, P[N + 5], Id[N + 5], x, y, op;
namespace Dist {
	int Dfn[M], lg[M], Bg[N], T[M][20], d[N], H;
	void dfs (int x, int La) {
		Dfn[Bg[x] = ++H] = x;
		d[x] = d[La] + 1;
		for (int i : S[x]) {
			dfs (i, x), Dfn[++H] = x;
		}
	}
	int LCA (int x, int y) {
		x = Bg[x];
		y = Bg[y];
		x > y  && (swap (x, y), 0);
		int D = lg[y - x + 1];
		return d[T[x][D]] < d[T[y - (1 << D) + 1][D]] ? T[x][D] : T[y - (1 << D) + 1][D];
	} int Dt (int x, int y) {
		return d[x] + d[y] - 2 * d[LCA (x, y)];
	}
	void BD() {
		int i, j;
		dfs (1, 0);
		for (i = 2; i <= H; i++) {
			lg[i] = lg[i / 2] + 1;
		}
		for (i = H; i; i--) {
			for (T[i][0] = Dfn[i], j = 1; i + (1 << j) - 1 <= H; j++) {
				T[i][j] = (d[T[i][j - 1]] < d[T[i + (1 << j - 1)][j - 1]] ? T[i][j - 1] : T[i + (1 << j - 1)][j - 1]);
			}
		}
	}
}
struct Ques {
	int x, y, Fl;
};
Ques Merge (Ques x, Ques y) {
	if (x.Fl == -1 || y.Fl == -1) return (Ques) {
		0, 0, -1
	};
	if (!x.Fl) {
		return y;
	}
	if (!y.Fl) {
		return x;
	}
	int D1 = Dist::Dt (x.x, x.y), D2 = Dist::Dt (x.x, y.x), D3 = Dist::Dt (x.x, y.y), D4 = Dist::Dt (x.y, y.x), D5 = Dist::Dt (x.y, y.y), D6 = Dist::Dt (y.x, y.y);
	if (D1 == D2 + D4 && D1 == D3 + D5) return (Ques) {
		x.x, x.y, 1
	};
	if (D2 == D3 + D6 && D2 == D1 + D4) return (Ques) {
		x.x, y.x, 1
	};
	if (D3 == D1 + D5 && D3 == D2 + D6) return (Ques) {
		x.x, y.y, 1
	};
	if (D4 == D1 + D2 && D4 == D5 + D6) return (Ques) {
		x.y, y.x, 1
	};
	if (D5 == D1 + D3 && D5 == D4 + D6) return (Ques) {
		x.y, y.y, 1
	};
	if (D6 == D2 + D3 && D6 == D4 + D5) return (Ques) {
		y.x, y.y, 1
	};
	return (Ques) {
		0, 0, -1
	};
}
namespace Tree {
#define ls v<<1
#define rs v<<1|1
	Ques F[M << 1];
	void Up (int v) {
		F[v] = Merge (F[ls], F[rs]);
	} void BD (int l = 0, int r = n - 1, int v = 1) {
		if (l == r) {
			F[v] = (Ques) {
				Id[l], Id[l], 1
			};
			return;
		}
		int m = l + r >> 1;
		BD (l, m, ls);
		BD (m + 1, r, rs);
		Up (v);
	}
	void Ins (int x, int l = 0, int r = n - 1, int v = 1) {
		if (l == r) {
			F[v] = (Ques) {
				Id[x], Id[x], 1
			};
			return;
		}
		int m = l + r >> 1;
		x <= m ? Ins (x, l, m, ls) : Ins (x, m + 1, r, rs);
		Up (v);
	}
	int Find (Ques x, int l = 0, int r = n - 1, int v = 1) {
		if (l == r) {
			return x = Merge (x, F[v]), ~x.Fl ? l + 1 : l;
		}
		int m = l + r >> 1;
		return ~Merge (x, F[ls]).Fl ? Find (Merge (x, F[ls]), m + 1, r, rs) : Find (x, l, m, ls);
	}
#undef ls
#undef rs
}
int main() {
//	freopen ("1.in", "r", stdin);
	int i, j;
	scanf ("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf ("%d", &P[i]), Id[P[i]] = i;
	}
	for (i = 2; i <= n; i++) {
		scanf ("%d", &x), S[x].push_back (i);
	}
	Dist::BD();
	Tree::BD();
	scanf ("%d", &m);
	while (m--) {
		scanf ("%d", &op);
		if (op == 2) printf ("%d\n", Tree::Find ( (Ques) {
			0, 0, 0
		}) );
		else {
			scanf ("%d%d", &x, &y), swap (P[x], P[y]), swap (Id[P[x]], Id[P[y]]), Tree::Ins (P[x]), Tree::Ins (P[y]);
		}
	}
}