#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, T, Ans[21000], cnt, SS[86420];
struct point{
	int b, e;
	bool operator<(const point &p)const{
		return b < p.b;
	}
}w[21000];
int main(){
	int i, hh, mm, ss, pv = 1, chk = 0;
	scanf("%d%d%d", &n, &m, &T);
	for (i = 1; i <= n; i++){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		w[i].b = hh * 3600 + mm * 60 + ss;
		w[i].e = w[i].b + T - 1;
		SS[w[i].b]++;
		SS[w[i].e + 1]--;
	}
	for (i = 1; i <= 86410; i++)SS[i] += SS[i - 1];
	for (i = 0; i <= 86410; i++){
		if (SS[i] >= m)chk = 1;
	}
	if (!chk){
		printf("No solution\n");
		return 0;
	}
	sort(w + 1, w + n + 1);
	cnt = 0;
	for (i = 1; i <= n; i++){
		while (pv <= n && w[pv].e < w[i].b)pv++;
		if (i == pv || cnt - Ans[pv] < m - 1){
			Ans[i] = ++cnt;
			continue;
		}
		else Ans[i] = cnt;
	}
	printf("%d\n", cnt);
	for (i = 1; i <= n; i++)printf("%d\n", Ans[i]);
}