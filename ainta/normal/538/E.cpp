#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n, D[201000][2], C[201000];
void DFS(int a){
	if (!E[a].size()){
		C[a] = 1;
		D[a][0] = D[a][1] = 1;
		return;
	}
	int i, x;
	for (i = 0; i < E[a].size(); i++){
		x = E[a][i];
		DFS(x);
		C[a] += C[x];
	}
	D[a][0] = C[a];
	D[a][1] = 0;
	for (i = 0; i < E[a].size(); i++){
		x = E[a][i];
		if (D[a][0] > C[x] - D[x][1] + 1)D[a][0] = C[x] - D[x][1] + 1;
		D[a][1] += C[x] - D[x][0];
	}
	D[a][1]++;
}
int main(){
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
	}
	DFS(1);
	printf("%d %d\n", C[1] - D[1][0] + 1, C[1] - D[1][1] + 1);
}