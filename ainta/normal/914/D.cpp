#include<cstdio>
#include<algorithm>
#define SZ 524288
using namespace std;
int IT[SZ + SZ];
int n, isPow[SZ+SZ+1];
int gcd(int a, int b) {
	return b?gcd(b, a%b) :a;
}
void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = gcd(IT[a * 2], IT[a * 2 + 1]);
	}
}
int Right(int a, int g) {
	a += SZ;
	while (1) {
		if (IT[a]%g)break;
		if (isPow[a + 1])return n + 1;
		a = (a + 1) >> 1;
	}
	while (a < SZ) {
		a *= 2;
		if (IT[a]%g == 0)a++;
	}
	return a-SZ;
}
int main() {
	int i, a, b, c, ck;
	for (i = 1; i <= SZ + SZ; i *= 2)isPow[i] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		Put(i, a);
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d%d",&ck, &a, &b);
		if (ck == 1) {
			scanf("%d", &c);
			int t = Right(a, c);
			if (t > b || Right(t + 1, c) > b)printf("YES\n");
			else printf("NO\n");
		}
		else {
			Put(a, b);
		}
	}
}