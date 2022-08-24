#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[300100];
int n, m, Ideg[300100], cnt, Q[300100], h, t;
struct order{
	int num, a;
	bool operator <(const order &p)const{
		return a < p.a;
	}
}ord[100100];
void Do(){
	int i, j, a, b1, b2;
	for (i = 1; i <= m; i++){
		scanf("%d", &a);
		ord[i].num = i, ord[i].a = a;
	}
	sort(ord + 1, ord + m + 1);
	for (i = 1; i <= m; i++){
		if (ord[i].a != -1)break;
	}
	b1 = i;
	b2 = -1;
	for (i = i; i <= m; i++){
		if (i == m || ord[i].a != ord[i + 1].a){
			if (b2 == -1){
				b2 = i;
				continue;
			}
			++cnt;
			for (j = b1; j <= b2; j++)E[ord[j].num].push_back(cnt);
			for (j = b2 + 1; j <= i; j++)E[cnt].push_back(ord[j].num);
			b1 = b2 + 1;
			b2 = i;
			continue;
		}
	}
}
int main()
{
	int i, j, x;
	scanf("%d%d", &n, &m);
	cnt = m;
	for (i = 1; i <= n; i++){
		Do();
	}
	for (i = 1; i <= cnt; i++){
		for (j = 0; j < E[i].size(); j++){
			Ideg[E[i][j]]++;
		}
	}
	for (i = 1; i <= cnt; i++){
		if (!Ideg[i])Q[++t] = i;
	}
	while (h < t){
		x = Q[++h];
		for (i = 0; i < E[x].size(); i++){
			Ideg[E[x][i]]--;
			if (!Ideg[E[x][i]])Q[++t] = E[x][i];
		}
	}
	if (t != cnt){
		printf("-1\n");
		return 0;
	}
	for (i = 1; i <= t; i++){
		if (Q[i] <= m)printf("%d ", Q[i]);
	}
}