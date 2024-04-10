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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 200005;

int N, F[N_], S[N_];
vector<int> Tree[N_];
queue<int> que, flp[2];
bool visited[N_];
int Level[N_];
vector<int> result;

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int u, v; scanf("%d%d", &u, &v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	for(int i = 1; i <= N; i++) scanf("%d", F+i);
	for(int i = 1; i <= N; i++) scanf("%d", S+i), S[i] ^= F[i];

	que.push(1); visited[1] = true;
	flp[0].push(0); flp[1].push(0);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		int f0 = flp[0].front(); flp[0].pop();
		int f1 = flp[1].front(); flp[1].pop();
		if(((Level[u] % 2 ? f1 : f0) ^ S[u]) == 1) {
			(Level[u] % 2 ? f1 : f0) ^= 1;
			result.push_back(u);
		}
		for(int e = 0; e < Tree[u].size(); e++) {
			int v = Tree[u][e]; if(!visited[v]) {
				visited[v] = true;
				Level[v] = Level[u] + 1;
				que.push(v);
				flp[0].push(f0);
				flp[1].push(f1);
			}
		}
	}

	printf("%d\n", result.size());
	for(int i = 0; i < result.size(); i++) printf("%d\n", result[i]);
	return 0;
}