#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int n, i, m, C, xx, b, e, C2, pv, yy;
struct point{
	int x, y;
	bool operator <(const point &p)const{
		return x != p.x ? x < p.x : y < p.y;
	}
}w[110000], P[410000], TP[410000];
int main(){
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d%d", &w[i].x, &w[i].y);
	}
	sort(w, w + m);
	if (w[m - 1].x == n && w[m - 1].y == n){
		printf("-1\n");
		return 0;
	}
	P[C].x = 1, P[C].y = 1, C = 1;
	xx = 0;
	for (i = 0; i < m; i++){
		if (xx + 1 != w[i].x){
			P[0].y = n;
			C = 1;
		}
		xx = w[i].x;
		b = i;
		C2 = 0;
		for (i = 0; i < C; i++){
			if (C2 && TP[C2 - 1].y >= P[i].y)continue;
			while (w[b].x == xx  && w[b].y < P[i].x)b++;
			yy = P[i].x;
			while (xx == w[b].x && P[i].x <= w[b].y && w[b].y < P[i].y){
				if(yy < w[b].y && (!C2 || TP[C2-1].y < w[b].y - 1))TP[C2].x = yy, TP[C2++].y = w[b].y - 1;
				yy = w[b].y + 1;
				b++;
			}
			if (w[b].x != xx){
				if (yy <= n)TP[C2].x = yy, TP[C2++].y = n;
				break;
			}
			else{
				if (yy < w[b].y)TP[C2].x = yy, TP[C2++].y = w[b].y - 1;
			}
		}
		for (i = 0; i < C2; i++)P[i] = TP[i];
		while (b < m && w[b].x == xx)b++;
		i = b - 1, C = C2;
		if (!C)break;
	}
	if (w[m - 1].x != n && C){
		P[0].y = n;
		C = 1;
	}
	if (C && P[C - 1].y == n)printf("%d\n", n * 2 - 2);
	else printf("-1\n");
}