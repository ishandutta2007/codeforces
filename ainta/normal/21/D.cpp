#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 99999999
int n, m, D[32768], w[15][15], S, C[15];
bool v[15];
struct A{
	int a, b;
	bool operator <(const A &p)const{
		return a < p.a;
	}
}tp, tp2;
priority_queue<A>PQ;
void DFS(int a){
	int i;
	v[a] = true;
	for (i = 0; i < n; i++){
		if (w[a][i] && !v[i])DFS(i);
	}
}
int main()
{
	int i, j, a, b, c;
	scanf("%d%d", &n, &m);
	while (m--){
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		if (!w[a][b] || w[a][b] > c)w[a][b] = w[b][a] = c;
		C[a]++, C[b]++;
		S += c;
	}
	DFS(0);
	for (i = 0; i < n; i++)if (C[i] && !v[i])break;
	if (i != n){
		printf("-1\n");
		return 0;
	}
	for (i = 0; i < (1 << n); i++)D[i] = INF;
	a = 0;
	for (i = 0; i < n; i++){
		a += (C[i] % 2)*(1 << i);
	}
	D[a] = 0;
	tp.a = 0, tp.b = a;
	PQ.push(tp);
	while (!PQ.empty()){
		tp = PQ.top();
		PQ.pop();
		tp.a = -tp.a;
		if (tp.a != D[tp.b])continue;
		if (tp.b == 0)break;
		for (i = 0; i < n; i++){
			for (j = i + 1; j < n; j++){
				if (!w[i][j])continue;
				a = (1 << i) + (1 << j);
				if (D[tp.b^a]>tp.a + w[i][j]){
					D[tp.b^a] = tp.a + w[i][j];
					tp2.a = -D[tp.b^a];
					tp2.b = tp.b^a;
					PQ.push(tp2);
				}
			}
		}
	}
	printf("%d\n", D[0] + S);
}