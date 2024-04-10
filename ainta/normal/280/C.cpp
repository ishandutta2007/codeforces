#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>E[100010];
int n;
double res;
void DFS(int a, int pp, int dep){
	int i;
	res += 1.0 / dep;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp){
			DFS(E[a][i], a, dep + 1);
		}
	}
}
int main()
{
	int a, b, i;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, -1, 1);
	printf("%.10lf\n", res);
}