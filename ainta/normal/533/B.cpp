#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
long long D[201000][2];
int n, w[201000];
void DFS(int a){
	int i;
	long long M1 = -99999999999999LL, M2 = 0, t1, t2;
	for (i = 0; i < E[a].size(); i++){
		DFS(E[a][i]);
		t1 = M1, t2 = M2;
		M1 = max(M1, t2 + D[E[a][i]][1]);
		M2 = max(M2, t1 + D[E[a][i]][1]);
		M1 = max(M1, t1 + D[E[a][i]][0]);
		M2 = max(M2, t2 + D[E[a][i]][0]);
	}
	D[a][0] = M2;
	D[a][1] = max(M1, M2 + w[a]);
}
int main(){
	int i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &a, &w[i]);
		if (a != -1)E[a].push_back(i);
	}
	DFS(1);
	printf("%lld\n", max(D[1][0], D[1][1]));
}