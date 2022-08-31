#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 1048576
#define pii pair<int,int>
using namespace std;
struct point {
	int a, b, num;
	bool operator <(const point &p)const {
		return a > p.a;
	}
}w[301000];
int n, Path[301000], D[301000], IT[SZ+SZ], Num[601000];
pii Max(int b, int e) {
	b += SZ, e += SZ;
	int Mx = -1, r = -1;
	while (b <= e) {
		if (Mx < IT[b])Mx = IT[b], r = b;
		if (Mx < IT[e])Mx = IT[e], r = e;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	while (r < SZ) {
		r *= 2;
		if (IT[r] != Mx)r++;
	}
	return pii(Mx, r - SZ);
}
void Put(int a, int b) {
	a += SZ;
	while (a) {
		IT[a] = max(IT[a], b);
		a >>= 1;
	}
}
vector<int>Calc() {
	int i;
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		Num[w[i].a] = i;
		Num[w[i].b] = i;
	}
	for (i = 1; i < SZ + SZ; i++)IT[i] = 0;
	int Mx = -1, pv = -1;
	for (i = 1; i <= n; i++) {
		if (w[i].a > w[i].b)continue;
		pii tp = Max(w[i].a + 1, 2 * n);
		D[i] = tp.first + 1;
		if (D[i] == 1)Path[i] = 0;
		else {
			Path[i] = Num[tp.second];
		}
		Put(w[i].b, D[i]);
		if (Mx < D[i])Mx = D[i], pv = i;
	}
	vector<int>Z;
	if (Mx == -1)return Z;
	while (pv) {
		Z.push_back(w[pv].num);
		pv = Path[pv];
	}
	reverse(Z.begin(), Z.end());
	return Z;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].a, &w[i].b);
		w[i].num = i;
	}
	vector<int>R1 = Calc();
	for (i = 1; i <= n; i++) {
		w[i].a = n + n + 1 - w[i].a;
		w[i].b = n + n + 1 - w[i].b;
	}
	vector<int>R2 = Calc();
	if (R1.size() < R2.size())R1 = R2;
	printf("%d\n", R1.size());
	for (auto &t : R1)printf("%d ", t);
}