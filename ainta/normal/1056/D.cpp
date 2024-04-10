#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, C[N_];
vector<int>E[N_];
void DFS(int a) {
	if(E[a].empty())C[a] = 1;
	for (auto &x : E[a]) {
		DFS(x);
		C[a] += C[x];
	}
}
int main() {
	int i, j, a;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	sort(C + 1, C + n + 1);
	for (i = 1; i <= n; i++)printf("%d ", C[i]);
}