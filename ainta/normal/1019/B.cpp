#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int R[101000];
int Query(int a) {
	while (a > n)a -= n;
	printf("? %d\n", a);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}
int Get(int a) {
	int b = Query(a);
	int e = Query(a + n / 2);
	return e - b;
}
void Do(int b, int e) {
	int mid = (b + e) >> 1;
	int t = Get(mid);
	if (!t) {
		printf("! %d\n", mid);
		return;
	}
	R[mid] = t;
	if (1ll * R[b] * R[mid] < 0)Do(b, mid);
	else Do(mid, e);
}
int main() {
	scanf("%d", &n);
	if (n % 4) {
		printf("! -1\n");
		return 0;
	}
	int t = Get(1);
	if (t == 0) {
		printf("! 1\n");
		return 0;
	}
	R[1] = t, R[1 + n / 2] = -t;
	Do(1, 1 + n / 2);
}