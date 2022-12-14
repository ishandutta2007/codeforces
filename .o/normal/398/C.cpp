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
typedef double lf;
typedef long double llf;
typedef unsigned long long llu; 

const int trees[10][10][3] = {
	{ },
	{ },
	{ 
		{0, 1, 1},
	},
	{ 
		{0, 2, 1},
		{0, 1, 1},
	},
	{ 
		{0, 2, 8},
		{0, 1, 4},
		{1, 3, 4},
	},
	{ 
		{0, 1, 4},
		{0, 3, 3},
		{1, 2, 6},
		{3, 4, 1},
	},
	{ 
		{0, 1, 6},
		{0, 3, 2},
		{1, 4, 2},
		{1, 2, 3},
		{4, 5, 4},	
	},
	{ 
		{0, 1, 7},
		{0, 5, 1},
		{0, 2, 10},
		{1, 4, 1},
		{2, 3, 1},
		{5, 6, 6},	
	},
	{ 
		{0, 4, 1},
		{0, 1, 3},
		{0, 3, 1},
		{1, 2, 2},
		{4, 7, 2},
		{5, 6, 3},
		{6, 7, 3},
	}
};

const int queries[10][10][2] = {
	{ },
	{ },
	{ },
	{ },
	{ {2, 3} },
	{ {2, 3}, {2, 4} },
	{ {2, 3}, {3, 4}, {3, 5} },
	{ {2, 4}, {3, 5}, {3, 6}, {4, 5}, {4, 6} },
	{ {2, 3}, {2, 5}, {3, 5}, {4, 5} }
};

const int num_queries[10] = {0, 0, 0, 0, 1, 2, 3, 5, 4};
const int num_queries_tail[10] = {0, 0, 0, 0, 1, 1, 1, 2, 0};
int n;
int table[100005], rec[100005];

int merged_tree[100005][3];
int merged_queries[100005][3];

int main() {
	scanf("%d", &n);
	for(int i = 4; i <= 8; i++) rec[i] = i, table[i] = num_queries[i];
	for(int i = 9; i <= n; i++) {
		for(int j = 2; j <= 8; j++) {
			int q = table[i-j] + (num_queries[j] - num_queries_tail[j]);
			if(q > table[i]) table[i] = q, rec[i] = j;
		}
	}

	int t = n, x = 1, q = 0, e = 0;
	while(t > 0) {
		int sz = rec[t];
		for(int i = 0; i < sz-1; i++) {
			merged_tree[e][0] = trees[sz][i][0] + x;
			merged_tree[e][1] = trees[sz][i][1] + x;
			merged_tree[e][2] = trees[sz][i][2];
			e++;
		}
		for(int i = 0; i < num_queries[sz] && q < n/2; i++) {
			if(t > 8 && queries[sz][i][1] == sz - 1) continue;
			merged_queries[q][0] = queries[sz][i][0] + x;
			merged_queries[q][1] = queries[sz][i][1] + x;
			q++;
		}
		x += sz;
		t -= sz;
		if(t > 0) {
			merged_tree[e][0] = x-1;
			merged_tree[e][1] = x;
			merged_tree[e][2] = 1;
			e++;
		}
	}
if(q < n/2) printf("queries = %d\n", q);

	for(int i = 0; i < e; i++) {
		for(int j = 0; j < 3; j++) printf("%d%c", merged_tree[i][j], (j == 2) ? '\n' : ' ');
	}

	for(int i = 0; i < q; i++) {
		for(int j = 0; j < 2; j++) printf("%d%c", merged_queries[i][j], (j == 1) ? '\n' : ' ');
	}
    return 0;
}