#pragma warning(disable:4996)
#include<stdio.h>
int n, k, C[310];
struct Point{
	double x, y;
}w[310][310], P[310], TP[310];
double S1, S2;
Point intersect(Point a, Point b, Point c, Point d){
	double t = ((d.y - b.y)*(a.x - b.x) - (d.x - b.x)*(a.y - b.y)) / ((c.x - d.x)*(a.y - b.y) - (c.y - d.y)*(a.x - b.x));
	Point r;
	r.x = t * c.x + (1 - t) * d.x;
	r.y = t * c.y + (1 - t) * d.y;
	return r;
}
void Do(int x, double y1, double y2){
	int i, pv1 = -1, pv2 = -1, c = 0;
	Point p1, p2;
	p1.x = x, p1.y = y1, p2.x = x + 1, p2.y = y2;
	for (i = 0; i < C[x]; i++){
		if (w[x][i].y < y1 + (y2 - y1)*(w[x][i].x - x)){
			if (pv1 == -1)pv1 = i;
			pv2 = i;
		}
	}
	if (pv1 == -1)return;
	if (pv1 == 0){
		TP[c++] = p1;
	}
	else{
		for (i = 0; i < pv1; i++)TP[c++] = w[x][i];
		TP[c++] = intersect(w[x][pv1 - 1], w[x][pv1], p1, p2);
	}
	if (pv2 == C[x] - 1){
		TP[c++] = p2;
	}
	else{
		TP[c++] = intersect(w[x][pv2], w[x][pv2 + 1], p1, p2);
		for (i = pv2 + 1; i < C[x]; i++){
			TP[c++] = w[x][i];
		}
	}
	C[x] = c;
	for (i = 0; i < c; i++)w[x][i] = TP[i];
}
void Calc(int x){
	int i;
	double r = 0;
	for (i = 0; i < C[x] - 1; i++){
		r += w[x][i].x * w[x][i + 1].y - w[x][i].y * w[x][i + 1].x;
	}
	r += x * w[x][0].y;
	r -= w[x][C[x] - 1].y * (x + 1);
	if (r < 0)r = -r;
	r /= 2;
	S1 += r;
}
int main()
{
	int i, j;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++){
		for(j = 0; j <= k; j++){
			scanf("%lf", &P[j].y);
			P[j].x = j;
		}
		S1 = 0;
		if (i == 1){
			for (j = 0; j < k; j++){
				w[j][0].x = j, w[j][1].x = j + 1;
				w[j][0].y = P[j].y, w[j][1].y = P[j + 1].y;
				C[j] = 2;
			}
		}
		else{
			for (j = 0; j < k; j++){
				Do(j, P[j].y, P[j+1].y);
			}
		}
		for (j = 0; j < k; j++){
			Calc(j);
		}
		printf("%.10lf\n", S1 - S2);
		S2 = S1;
	}
	return 0;
}