#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int ans[MAXN];
int mini[MAXN];

int main() {
	memset(mini, INF, sizeof mini);
	
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < 10; i++) {
		vector <int> tmp;
		for (int j = 0; j < N; j++)
			if (j >> i & 1)
				tmp.push_back(j + 1);
		if (tmp.empty()) 
			continue;
		printf("%d\n", tmp.size());
		for (int it : tmp)
			printf("%d ", it);
		fflush(stdout);
		for (int j = 0; j < N; j++)
			scanf("%d", ans + j);
		for (int j = 0; j < N; j++)
			if (!(j >> i & 1))
				mini[j] = min(mini[j], ans[j]);
	}
	
	for (int i = 0; i < 10; i++) {
		vector <int> tmp;
		for (int j = 0; j < N; j++)
			if (!(j >> i & 1))
				tmp.push_back(j + 1);
		if (tmp.empty()) 
			continue;
		printf("%d\n", tmp.size());
		for (int it : tmp)
			printf("%d ", it);
		fflush(stdout);
		for (int j = 0; j < N; j++)
			scanf("%d", ans + j);
		for (int j = 0; j < N; j++)
			if (j >> i & 1)
				mini[j] = min(mini[j], ans[j]);
	}
	
	puts("-1");
	for (int i = 0; i < N; i++)
		printf("%d ", mini[i]);
	fflush(stdout);
	
	return 0;
}