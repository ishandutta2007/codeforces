#include<cstdio>
#include<algorithm>
using namespace std;
int m, top;
long long n, SA, SB;
struct point {
	long long A, B;
}st[401000];
bool Over(point a, point b, point c) {
	return 1.0L*(a.B - b.B)/(b.A - a.A) <= 1.0L*(a.B - c.B)/(c.A - a.A);
}
void Put(long long A, long long B) {
	point tp = { A,B };
	while (top > 1 && Over(st[top - 1], st[top], tp))top--;
	st[++top] = tp;
}
void Go(long long A, long long B) {
	long long pv = 1;
	long long r = B;
	if (!top) {
		printf("%lld %lld\n", pv, r);
		return;
	}
	int b = 2, e = top, mid, cur = 1;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (A*st[mid].A + st[mid].B < A*st[mid - 1].A  + st[mid - 1].B) {
			cur = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	if (r > A*st[cur].A + st[cur].B + B) {
		r = A * st[cur].A + st[cur].B + B;
		pv = st[cur].A + 1;
	}
	printf("%lld %lld\n", pv, r);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, ck, a, b, chk = 1;
	scanf("%lld%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &ck, &a);
		if (ck == 1) {
			top = 0;
			n += a;
			SA = SB = 0;
			printf("1 0\n");
			continue;
		}
		if (ck == 2) {
			if(chk)Put(n, -SA*n-SB);
			n += a;
			chk = 0;
			Go(SA, SB);
		}
		if (ck == 3) {
			chk = 1;
			scanf("%d", &b);
			SA += b;
			SB += a;
			Go(SA, SB);
		}
	}
}