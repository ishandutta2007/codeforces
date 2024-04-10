#include<cstdio>
#include<algorithm>
#define N_ 201000
#define SZ 524288
using namespace std;
int n, Q, w[N_], IT[SZ+SZ], S[N_];
char qq[3];
struct point {
	char ch;
	int a;
}P[N_];
void Put(int a, int b) {
	a += SZ;
	while (a) {
		IT[a] = b;
		a >>= 1;
	}
}
int Max(int b, int e) {
	int r = 0;
	b += SZ, e += SZ;
	while (b <= e) {
		r = max(r, max(IT[b], IT[e]));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int main() {
	int i;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		w[i] *= 2;
	}
	int MM = 210000;
	for (i = 1; i <= Q; i++) {
		scanf("%s", qq);
		scanf("%d", &P[i].a);
		if (qq[0] == '>')P[i].a = P[i].a * 2 + 1;
		if (qq[0] == '<')P[i].a = P[i].a * 2 - 1;
		P[i].ch = qq[0];
		Put(P[i].a+MM, i);
		S[i] = S[i - 1];
		if (P[i].a > 0 && qq[0] == '<')S[i]++;
		if (P[i].a < 0 && qq[0] == '>')S[i]++;
	}
	for (i = 1; i <= n; i++) {
		int x = abs(w[i]);
		int L = Max(-x + MM, x + MM);
		if (L != 0) {
			if (P[L].ch == '<') w[i] = x;
			else w[i] = -x;
		}
		if ((S[Q] - S[L]) % 2)w[i] = -w[i];
		printf("%d ", w[i] / 2);
	}

}