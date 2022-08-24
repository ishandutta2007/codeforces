#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n;
long long Mod = 1000000007, D[201000], DP[201000];
void DFS(int a){
	int i;
	long long t = 1;
	for (i = 0; i < E[a].size(); i++){
		DFS(E[a][i]);
		t = t * (D[E[a][i]] + 1) % Mod;
	}
	D[a] = t;
}
long long D1[201000];
void Do(int a){
	int i;
	long long t = 1;
	if (a == 1)DP[a] = 1;
	D1[0] = 1;
	for (i = 0; i < E[a].size(); i++){
		D1[i + 1] = D1[i] * (D[E[a][i]] + 1) % Mod;
	}
	for (i = E[a].size() - 1; i >= 0; i--){
		DP[E[a][i]] = (t * D1[i] % Mod *DP[a] + 1) % Mod;
		t = t * (D[E[a][i]] + 1) % Mod;
	}
	for (i = 0; i < E[a].size(); i++)Do(E[a][i]);
}
int main(){
	int i, a;
	scanf("%d", &n);
	for (i = 2; i <= n; i++){
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	Do(1);
	for (i = 1; i <= n; i++)printf("%lld ", DP[i] * D[i] % Mod);
}