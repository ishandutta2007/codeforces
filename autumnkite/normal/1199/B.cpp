#include <cstdio>
double L, H;
signed main(){
	scanf("%lf%lf", &H, &L);
	printf("%.10lf\n", (L * L - H * H) / (2.0 * H));
}