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

const int L = 100055;

int N, K;
char S[100005];
int num[L][26],T;

bool Table1[L];
bool dfs1 (int u) {
	for(int i = 0; i < 26; i++) {
		int v = num[u][i];
		if(v >= 0) if(!dfs1(v)) return Table1[u] = true;
	}
	return false;
}
bool Table2[L];
bool dfs2 (int u) {
	bool is_leaf = true;
	for(int i = 0; i < 26; i++) {
		int v = num[u][i];
		if(v >= 0) is_leaf = false;
	}

	if(is_leaf) return Table2[u] = true;
	
	for(int i = 0; i < 26; i++) {
		int v = num[u][i];
		if(v >= 0) if(!dfs2(v)) return Table2[u] = true;
	}
	
	return false;
}

int main() {
	scanf("%d%d", &N, &K);
	memset(num, -1, sizeof num);
	for(int i = 0; i < N; i++) {
		scanf("%s", S);
		for(int x = -1, p = 0; S[++x]; ) {
			int c = S[x]-'a';
			if(num[p][c] < 0) num[p][c] = ++T;
			p = num[p][c];
		}
	}

	bool ret1 = dfs1(0);
	bool ret2 = dfs2(0);

	K = K % 24;
	if(K == 0) K += 24;
	
	bool res = 0;
	while(K--) res = res ? ret2 : ret1;

	puts(res ? "First" : "Second");
	return 0;
}