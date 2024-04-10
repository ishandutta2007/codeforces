#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define Buck_SZ 1000
using namespace std;
vector<int>E[200010];
char p[50010];
int n, D[201][200010], C[100], cnt, numb[531444], m, Q, Len[531444], Gap[50010][4];
int num2[200010];
struct point{
	int a, num;
	bool operator<(const point &p)const{
		return a != p.a ? a < p.a : num < p.num;
	}
}ord[331444];
int Gap2(int a, int b){
	return D[a][b];
}
int Pro(int a, int b){
	int i, j, pv1 = 0, pv2 = 0, r = 999999999, t;
	int L1 = Len[a], L2 = Len[b];
	while (pv1 < E[a].size() && pv2 < E[b].size()){
		t = max(E[a][pv1] + L1, E[b][pv2] + L2) - min(E[a][pv1], E[b][pv2]);
		if (r > t)r = t;
		if (E[a][pv1] < E[b][pv2])pv1++;
		else pv2++;
	}
	return r;
}
int main()
{
	int i, j, k, t, x, c = 0, pv, LL;
	scanf("%s", p);
	for (j = 0; p[j]; j++);
	n = j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < n - i; j++){
			t = 0;
			for (k = 0; k <= i; k++){
				t *= 27;
				t += (p[j + k] - 'a' + 1);
			}
			Gap[j][i] = t;
			ord[c].num = j;
			ord[c].a = t;
			c++;
		}
	}
	sort(ord, ord + c);
	for (i = 0; i < c; i++){
		if (!i || ord[i].a != ord[i - 1].a){
			numb[ord[i].a] = ++m;
		}
		E[m].push_back(ord[i].num);
	}
	for (i = 1; i <= 531443; i++){
		t = i, x = 0;
		while (t){
			t /= 27;
			x++;
		}
		Len[numb[i]] = x;
	}
	for (i = 1; i <= m; i++){
		if (E[i].size() >= Buck_SZ){
			C[++cnt] = i;
			num2[i] = cnt;
		}
	}
	int g;
	for (i = 1; i <= cnt; i++){
		pv = 0;
		LL = Len[C[i]];
		x = C[i];
		for (j = 0; j < 4; j++){
			pv = 0;
			for (k = 0; k < n - j; k++){
				g = numb[Gap[k][j]];
				while (pv + 1 < E[x].size() && max(k + j, E[x][pv] + LL) - min(k, E[x][pv]) >= max(k + j, E[x][pv + 1] + LL) - min(k, E[x][pv + 1])) pv++;
				if(!D[i][g])D[i][g] = max(k + j, E[x][pv] + LL - 1) - min(k, E[x][pv]) + 1;
				else D[i][g] = min(D[i][g], max(k + j, E[x][pv] + LL - 1) - min(k, E[x][pv]) + 1);
			}
		}
	}
	scanf("%d", &Q);
	char p1[10], p2[10];
	int t1, t2;
	while (Q--){
		scanf("%s%s", p1, p2);
		t1 = t2 = 0;
		for (i = 0; p1[i]; i++){
			t1 *= 27;
			t1 += (p1[i] - 'a' + 1);
		}
		for (i = 0; p2[i]; i++){
			t2 *= 27;
			t2 += (p2[i] - 'a' + 1);
		}
		t1 = numb[t1], t2 = numb[t2];
		if (!t1 || !t2){
			printf("-1\n");
			continue;
		}
		if (E[t1].size() >= Buck_SZ){
			printf("%d\n", Gap2(num2[t1], t2));
		}
		else if (E[t2].size() >= Buck_SZ){
			printf("%d\n", Gap2(num2[t2], t1));
		}
		else{
			printf("%d\n", Pro(t1, t2));
		}
	}
}