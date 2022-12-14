#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 100500;

int N, M;
vector<int> gph[2][N_];

int visited[N_];

bool good(int u, int t) {
	if (visited[u] >= 0) return visited[u] == t;
	visited[u] = t;
	for (int k = 0; k < 2; k++) for (int e = 0; e < gph[k][u].size(); e++) {
		if (!good(gph[k][u][e], t ^ k)) return false;
	}
	return true;
}

const ll MOD = (ll)1e9 + 7;

int main() {

	scanf("%d%d", &N, &M);
	for (int e = 0; e < M; e++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		gph[!c][a].push_back(b);
		gph[!c][b].push_back(a);
	}
	
	memset(visited, -1, sizeof visited);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != -1) continue;
		if (!good(i, 0)) return 0 & puts("0");
		cnt++;
	}

	ll ans = 1;
	for (int i = 0; i < cnt - 1; i++) ans = (ans * 2) % MOD;
	printf("%I64d\n", ans);

	return 0;
}