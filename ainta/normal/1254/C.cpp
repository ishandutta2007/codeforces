#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, DEBUG = 0;
struct point {
	long long x, y;
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
}w[20];
long long Q1(int i, int j, int k) {
	long long s;
	printf("1 %d %d %d\n", i, j, k);
	fflush(stdout);
	if (!DEBUG) {
		scanf("%lld", &s);
	}
	else {
		point t1 = w[j] - w[i];
		point t2 = w[k] - w[i];
		return abs(t1.x*t2.y - t2.y*t1.x);
	}
	return s;
}
int Q2(int i, int j, int k) {
	int sign;
	printf("2 %d %d %d\n", i, j, k);
	fflush(stdout);
	if (!DEBUG) {
		scanf("%d", &sign);
	}
	else {

		point t1 = w[j] - w[i];
		point t2 = w[k] - w[i];
		return t1.x*t2.y - t2.x*t1.y > 0 ? 1 : -1;
	}
	return sign;
}
struct AA {
	long long s;
	int num;
	bool operator <(const AA &p)const {
		return s < p.s;
	}
}T[1010];
long long S[1010];
int A[1010], B[1010], CA, CB;
int main() {
	int i;
	scanf("%d", &n);
	if (DEBUG) {
		for (i = 1; i <= n; i++)scanf("%lld%lld", &w[i].x, &w[i].y);
	}
	int pv = 2;
	for (i = 3; i <= n; i++) {
		if (Q2(1, pv, i) < 0)pv = i;
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (i != 1 && i != pv) {
			S[i] = Q1(1, pv, i);
			T[++cnt] = { S[i], i };
		}
	}
	sort(T + 1, T + cnt + 1);
	A[++CA] = 1;
	B[++CB] = pv;
	for (i = 1; i < cnt; i++) {
		if (Q2(1, T[i].num, T[i + 1].num) < 0)A[++CA] = T[i].num;
		else B[++CB] = T[i].num;
	}
	A[++CA] = T[cnt].num;
	printf("0 1 ");
	for (i = 1; i <= CB; i++)printf("%d ", B[i]);
	for (i = CA; i > 1; i--)printf("%d ", A[i]);
	puts("");
	fflush(stdout);
}