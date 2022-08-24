#include<stdio.h>
struct point{
	double x, y;
}B, E, P, Q;
int n;
bool ccw(point a, point b, point c){
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) < 0;
}
int main(){
	scanf("%lf%lf%lf%lf", &B.x, &B.y, &E.x, &E.y);
	int i, a, b, c, r = 0;
	double aa, bb, cc;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		aa = a, bb = b, cc = c;
		if (b != 0){
			P.x = -(2e6), Q.x = 2e6;
			P.y = -(P.x*aa + cc) / bb;
			Q.y = -(Q.x*aa + cc) / bb;
		}
		else{
			P.y = -(2e6), Q.y = 2e6;
			P.x = -(P.y*bb + cc) / aa;
			Q.x = -(Q.y*bb + cc) / aa;
		}
		if (ccw(B, E, P) != ccw(B, E, Q) && ccw(P, Q, B) != ccw(P, Q, E))r++;
	}
	printf("%d\n", r);
}