#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int S[201000];
int n, m, vis[201000], cnt;
vector<int>E[201000];
void DFS(int a) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x])DFS(x);
	}
}
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		if (a > b)swap(a, b);
		E[a].push_back(b);
		E[b].push_back(a);
		S[a]++, S[b]--;
	}
	for (i = 1; i <= n; i++)S[i] += S[i - 1];
	int CC = 1;
	for (i = 1; i < n; i++) {
		if (!S[i])CC++;
	}
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt++;
			DFS(i);
		}
	}
	printf("%d\n", cnt - CC);
}