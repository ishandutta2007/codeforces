#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[401000], Num[401000];
int Col[201000], st[401000], deg[401000], pp[401000];
int CC[401000];
bool v[401000];
int n, top;
void Ins(int a){
	top++;
	st[top] = a;
	v[a] = true;
}
void DFS(int a){
	top = 0;
	int i, x, y, z, ck;
	Ins(a);
	while (1){
		while (top){
			x = st[top];
			y = pp[x];
			if (y == E[x].size()){
				v[x] = false;
				top--;
			}
			else{
				if (Col[Num[x][y]] || st[top-1] == E[x][y]) pp[x]++;
				else break;
			}
		}
		if (!top)break;
		x = st[top];
		y = pp[x];
		z = E[x][y];
		pp[x]++;
		if (v[z]){
			ck = 1;
			Col[Num[x][y]] = ck;
			while (st[top] != z){
				ck = 3 - ck;
				Col[Num[st[top - 1]][pp[st[top - 1]] - 1]] = ck;
				v[st[top]] = false;
				top--;
			}
			continue;
		}
		Ins(z);
	}
}
void Do(int a){
	int i, ck = 1;
	if (deg[a] % 2 == 1 && CC[a] == 1)ck = 2;
	for (i = 0; i < E[a].size(); i++){
		if (Col[Num[a][i]])continue;
		Col[Num[a][i]] = ck;
		if (ck == 1)CC[E[a][i]]++;
		else CC[E[a][i]]--;
		ck = 3 - ck;
		deg[E[a][i]]--;
		Do(E[a][i]);
	}
}
int main(){
	int i, a, b, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b + 200000); Num[a].push_back(i);
		E[b + 200000].push_back(a); Num[b + 200000].push_back(i);
	}
	for (i = 1; i <= 400000; i++){
		if(!v[i])DFS(i);
	}
	for (i = 1; i <= 400000; i++){
		for (j = 0; j < E[i].size(); j++){
			if (!Col[Num[i][j]])deg[i]++;
		}
	}
	for (i = 1; i <= 400000; i++){
		if (deg[i])Do(i);
	}
	for (i = 1; i <= n; i++)printf("%c", Col[i]==1?'r':'b');
	return 0;
}