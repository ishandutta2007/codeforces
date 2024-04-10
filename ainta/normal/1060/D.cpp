#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	int x, num;
	bool operator <(const point &p)const {
		return x < p.x;
	}
}A[101000], B[101000];
int n;
long long res;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &A[i].x, &B[i].x);
		A[i].num = i, B[i].num = i;
		res += A[i].x + B[i].x + 1;
	}
	sort(A, A + n);
	sort(B, B + n);
	for (i = 0; i < n; i++) {
		res -= min(A[i].x, B[i].x);
	}
	printf("%lld\n", res);
}