#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n, st[3010], cnt, m;
struct point{
	int x, y;
	bool operator <(const point &p)const{
		return x != p.x ? x < p.x : y < p.y;
	}
}w[3010], P[3010], Q[6010];
int ccw(point a, point b, point c){
	int t = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	if (t < 0)return -1;
	if (t == 0)return 0;
	return 1;
}
void Convex_Hull(){
	int i, top = 0;
	st[++top] = 1;
	for (i = 2; i <= n; i++){
		if (top > 1 && ccw(w[st[top - 1]], w[st[top]], w[i]) < 0)top--;
		st[++top] = i;
	}
	for (i = 1; i < top; i++){
		P[++cnt] = w[st[i]];
	}
	top = 0;
	st[++top] = 1;
	for (i = 2; i <= n; i++){
		if (top > 1 && ccw(w[st[top - 1]], w[st[top]], w[i]) > 0)top--;
		st[++top] = i;
	}
	for (i = top; i >= 2; i--){
		P[++cnt] = w[st[i]];
	}
}
int dis(point a, point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int L_dis(){
	int i, pv = 1, res = 0;
	for (i = 1; i <= m; i++)Q[m + i] = Q[i];
	for (i = 1; i <= m; i++){
		while (dis(Q[i], Q[pv]) < dis(Q[i], Q[pv + 1]))pv++;
		res = max(res, dis(Q[i], Q[pv]));
	}
	return res;
}
int main()
{
	int i, j, B = 1, E = 800000000, R = 0, M;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &w[i].x, &w[i].y);
	}
	sort(w + 1, w + n + 1);
	Convex_Hull();
	while (B <= E){
		M = (B + E) >> 1;
		for (i = 1; i <= n; i++){
			m = 0;
			for (j = 1; j <= cnt; j++){
				if (dis(w[i], P[j]) >= M)Q[++m] = P[j];
			}
			if (L_dis() >= M)break;
		}
		if (i == n + 1){
			E = M - 1;
		}
		else{
			R = M;
			B = M + 1;
		}
	}
	double res = R;
	printf("%lf\n", sqrt(res)*0.5);
}