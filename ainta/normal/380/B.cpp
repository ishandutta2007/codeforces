#pragma warning(disable:4996)
#include<stdio.h>
using namespace std;
int p[110000][2], n, i, m, cnt, j, pv, pv2;
struct A{
	int d, l, r, x;
}w[7010];
bool v[1010000];
int main(){
	int a, b, c, d, e, C = 0;
	scanf("%d%d", &n, &m);
	cnt = 1;
	for (i = 2; i < n; i++){
		for (j = 0; (1 << j) <= cnt; j++);
		cnt += j;
	}
	pv = 1, pv2 = 1;
	for (i = 1; i <= cnt; i++){
		if (pv2 == i){
			p[i][0] = pv++;
			p[i][1] = pv++;
			pv2 *= 2;
		}
		else{
			p[i][0] = p[i][1] = pv;
			pv++;
		}
	}
	while (m--){
		scanf("%d%d%d", &a, &b, &c);
		if (a == 2){
			d = c;
			cnt = 0;
			for (i = 1; i <= C; i++){
				while (b < w[i].d){
					b++;
					c = p[c][0], d = p[d][1];
				}
				if (v[w[i].x])continue;
				if (b == w[i].d && c <= w[i].r && d >= w[i].l){
					v[w[i].x] = true;
					cnt++;
				}
			}
			printf("%d\n", cnt);
			for (i = 1; i <= C; i++)v[w[i].x] = false;
			continue;
		}
		scanf("%d%d", &d, &e);
		for (i = 1; i <= C; i++){
			if (w[i].d > b)break;
		}
		a = i;
		for (i = C; i >= a; i--)w[i + 1] = w[i];
		w[a].d = b, w[a].l = c, w[a].r = d, w[a].x = e;
		C++;
	}
}