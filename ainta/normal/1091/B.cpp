#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	int x, y;
	bool operator <(const point &p)const {
		return x != p.x ? x < p.x : y < p.y;
	}
}A[1100], B[1100];
int n;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &A[i].x, &A[i].y);
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d", &B[i].x, &B[i].y);
	}
	sort(A, A + n);
	sort(B, B + n);
	printf("%d %d\n", A[0].x + B[n - 1].x, A[0].y + B[n - 1].y);
}