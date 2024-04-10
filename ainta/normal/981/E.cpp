#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#define SZ 16384
using namespace std;
bitset<10001>D[20], Res;
int n, Q;
vector<int>E[SZ + SZ];
void Put(int b, int e, int c) {
	b += SZ, e += SZ;
	while (b <= e) {
		if (b & 1)E[b].push_back(c);
		if (!(e & 1))E[e].push_back(c);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
void Do(int dep, int nd, int b, int e) {
	if (b > n)return;
	D[dep + 1] = D[dep];
	for (auto &x : E[nd]) {
		D[dep + 1] = (D[dep + 1] | (D[dep+1] <<  x));
	}
	if (b == e) {
		Res |= D[dep + 1];
		return;
	}
	int m = (b + e) >> 1;
	Do(dep + 1, nd * 2, b, m);
	Do(dep + 1, nd * 2 + 1, m + 1, e);
}
int main() {
	int i, b, e, c;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%d%d%d", &b, &e, &c);
		Put(b, e, c);
	}
	D[0][0] = 1;
	Do(0 ,1, 0, SZ-1);
	vector<int>r;
	for (i = 1; i <= n; i++) {
		if (Res[i] == 1)r.push_back(i);
	}
	printf("%d\n", r.size());
	for (auto &x : r)printf("%d ", x);
}