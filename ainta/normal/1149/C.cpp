#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
struct Tree {
	int U, D, UD, Mn, Mx, sum;
}IT[SZ+SZ];
Tree Merge(Tree a, Tree b) {
	Tree r;
	r.Mx = max(a.Mx, a.sum + b.Mx);
	r.Mn = min(a.Mn, a.sum + b.Mn);
	r.U = max(max(a.U, b.U - a.sum), a.Mx - (a.sum + b.Mn) * 2);
	r.D = max(max(a.D, b.D - a.sum), (b.Mx + a.sum) - a.Mn * 2);
	r.UD = max(max(a.UD, b.UD), max(a.U + (a.sum + b.Mx), a.Mx + (b.D - a.sum) ));
	r.sum = a.sum + b.sum;
	return r;
}
Tree Make(int a) {
	int b = 0, e = a;
	Tree r;
	r.Mx = max(b, e);
	r.Mn = min(b, e);
	r.sum = e;
	r.U = max(max(-b, -e), b - e * 2);
	r.D = max(max(-b, -e), e - b * 2);
	r.UD = max(b - e, e - b);
	return r;
}
int n, Q;
char p[201000];
void Put(int a) {
	if (p[a] == '(') {
		IT[SZ + a] = Make(1);
	}
	else {
		IT[SZ + a] = Make(-1);
	}
	a += SZ;
	while (a != 1) {
		a >>= 1;
		IT[a] = Merge(IT[a * 2], IT[a * 2 + 1]);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, a, b;
	scanf("%d%d", &n, &Q);
	scanf("%s", p+1);
	for (i = 1; i <= 2 * n - 2; i++) {
		Put(i);
	}
	printf("%d\n", IT[1].UD);
	while (Q--) {
		scanf("%d%d", &a, &b);
		swap(p[a], p[b]);
		Put(a);
		Put(b);
		printf("%d\n", IT[1].UD);
	}
}