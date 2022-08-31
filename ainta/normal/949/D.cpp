
#include<cstdio>
#include<algorithm>
#define N_ 101000
using namespace std;
int n, L, d, w[N_], B[N_], E[N_], ord[N_];
struct Range {
	int b, e, c;
}P[N_];
bool Pos(int K) {
	int i;
	for (i = 1; i <= n; i++){
		P[i] = { B[i],E[i],w[i] };
	}
	int p1 = 1, p2 = 1;
	int s = 0, c = 0;
	for (i = 1; i <= (n+1)/2; i++) {
		while (p2 <= n && P[p2].b <= i) {
			s += P[p2].c;
			p2++;
		}
		if (s < L)c++;
		if (s >= L) {
			int t = L;
			while (p1 <= n && t) {
				int tp= min(P[p1].c, t);
				t -= tp;
				P[p1].c -= tp;
				if (!P[p1].c)p1++;
			}
			s -= L;
		}
	}
	if (c > K)return false;
	p1 = n, p2 = n, c = 0;
	s = 0;
	for (i = n; i > (n + 1) / 2; i--) {
		while (p2 >= 1 && P[p2].e >= i) {
			s += P[p2].c;
			p2--;
		}
		if (s < L)c++;
		if (s >= L) {
			int t = L;
			while (p1 >= 1 && t) {
				int tp = min(P[p1].c, t);
				t -= tp;
				P[p1].c -= tp;
				if (!P[p1].c)p1--;
			}
			s -= L;
		}
	}
	if (c > K)return false;
	return true;
}
int main() {
	int i;
	scanf("%d%d%d", &n, &d, &L);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		ord[i] = min(i, n + 1 - i);
	}
	for (i = 1; i <= n; i++) {
		int b = 1, e = i, mid, r = i;
		while (b <= e) {
			mid = (b + e) >> 1;
			if ((i - mid + d - 1) / d <= ord[mid]) r = mid, e = mid - 1;
			else b = mid + 1;
		}
		B[i] = r;
		b = i, e = n, mid, r = i;
		while (b <= e) {
			mid = (b + e) >> 1;
			if ((mid - i + d - 1) / d <= ord[mid]) r = mid, b = mid + 1;
			else e = mid - 1;
		}
		E[i] = r;
	}
	int b = 0, e = (n + 1)/2, r = n, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(mid))r = mid, e = mid - 1;
		else b = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}