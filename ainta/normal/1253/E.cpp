#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, L, chk[81];
struct point {
	int b, e;
	bool operator <(const point &p)const {
		return b < p.b;
	}
}w[81];
int D[101000], T[101000];
int main() {
	int i, j;
	scanf("%d%d", &n,&L);
	for (i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		w[i] = { max(x - y,1),min(x + y,L) };
	}
	for (i = 1; i <= L; i++)D[i] = 1e9;
	for (int ii = 1; ii <= n; ii++) {
		for (i = 1; i <= n; i++) {
			for (j = 0; j <= L; j++)T[j] = D[j];
			for (j = 0; j <= L; j++) {
				D[min(w[i].e + j, L)] = min(D[min(w[i].e + j, L)], T[max(w[i].b - j - 1, 0)] + j);
			}
			for (j = L - 1; j >= 0; j--)D[j] = min(D[j], D[j + 1]);
		}
	}
	printf("%d\n", D[L]);
}