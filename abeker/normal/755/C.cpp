#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10005;

int N;
int p[MAXN];
bool bio[MAXN];
vector <int> E[MAXN];

void dfs(int x) {
	bio[x] = true;
	for (int nxt : E[x])
		if (!bio[nxt])
			dfs(nxt);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", p + i);
		E[i].push_back(p[i]);
		E[p[i]].push_back(i);
	}
	
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		if (bio[i])
			continue;
		dfs(i);
		sol++;
	}
	
	printf("%d\n", sol);
	
	return 0;
}