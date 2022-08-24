#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[50][50];
int n, UF[50], SZ[50], Num[50], cnt, E[23];
int D[1 << 23];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b)UF[a] = b;
}
void Put(int a, int b) {
	E[a] |= (1 << b);
	E[b] |= (1 << a);
}
int Cur;
vector<int>UU;
void BronKerbosch2(int R, int P, int X) {
	if (!P && !X) {
		UU.push_back(R);
		return;
	}
	int i;
	for (i = 0; i < cnt; i++) {
		if (((P | X) >> i) & 1)break;
	}
	int u = i;
	for (i = 0; i < cnt; i++) {
		if (((P >> i) & 1) && !((E[u] >> i) & 1)) {
			BronKerbosch2(R | (1 << i), P&E[i], X&E[i]);
			P = P&(~(1 << i));
			X = X | (1 << i);
		}
	}
}
void Solve(int mask) {
	if (!mask) {
		D[mask] = 0;
		return;
	}
	if (D[mask] != -1)return;
	BronKerbosch2(0, mask, 0);
	vector<int>PP = UU;
	UU.clear();
	D[mask] = 1e9;
	for (int &t : PP) {
		Solve(mask^t);
		D[mask] = min(D[mask], D[mask^t] + 1);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
		UF[i] = i;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (p[i][j] == 'A')Merge(i, j);
		}
	}
	for (i = 1; i <= n; i++) {
		SZ[Find(i)]++;
	}
	for (i = 1; i <= n; i++) {
		if (SZ[i] >= 2)Num[i] = cnt++;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (Find(i) == Find(j) && p[i][j] == 'X') {
				printf("-1\n");
				return 0;
			}
			if (p[i][j] == 'X' && SZ[Find(i)] >= 2 && SZ[Find(j)] >= 2) {
				Put(Num[Find(i)], Num[Find(j)]);
			}
		}
	}
	for (i = 0; i < cnt; i++) {
		E[i] ^= (1 << cnt) - 1;
		if (E[i] & (1 << i)) E[i] ^= (1 << i);
	}
	if (!cnt) {
		printf("%d\n", n - 1);
		return 0;
	}
	D[0] = 0;
	for (i = 0; i < (1 << cnt); i++)D[i] = -1;
	Solve((1 << cnt) - 1);
	printf("%d\n", D[(1 << cnt) - 1] + n - 1);
}