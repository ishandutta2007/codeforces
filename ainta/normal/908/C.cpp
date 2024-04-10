#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point {
	int x;
	double y;
}w[1010];
int n, R;
int main() {
	int i, j;
	scanf("%d%d", &n, &R);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i].x);
		double Mx = 1.0*R;
		for (j = 1; j < i; j++) {
			if ((w[j].x - w[i].x) * (w[j].x - w[i].x) > 4 * R*R)continue;
			Mx = max(Mx, w[j].y + sqrt(max(0.0,4.0*R*R - (w[j].x - w[i].x) * (w[j].x - w[i].x))));
		}
		w[i].y = Mx;
		printf("%.10f ", w[i].y);
	}
}