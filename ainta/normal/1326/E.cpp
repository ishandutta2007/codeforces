#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
int n, A[301000], B[301000], Loc[301000];
struct Tree {
	int S, R;
}IT[SZ+SZ];
Tree Merge(Tree a, Tree b) {
	Tree r;
	r.S = a.S + b.S;
	r.R = min(b.R, b.S + a.R);
	return r;
}
void Add(int a, int b) {
	a += SZ;
	IT[a].S += b;
	IT[a].R = min(0, IT[a].S);
	while (a != 1) {
		a >>= 1;
		IT[a] = Merge(IT[a * 2], IT[a * 2 + 1]);
	}
}
int main() {
	int i;
	scanf("%d", &n);
	int Mx = -1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		Loc[A[i]] = i;
	}
	int pv = n;
	for (i = 1; i <= n; i++) {
		printf("%d ", pv);
		scanf("%d", &B[i]);
		if (i == n)break;
		Add(B[i], 1);
		while (1) {
			Add(Loc[pv], -1);
			if (IT[1].R < 0) {
				Add(Loc[pv], 1);
				break;
			}
			pv--;
		}
	}
}