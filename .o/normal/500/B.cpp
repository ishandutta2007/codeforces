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

const int N_ = 1050;
int N;
int P[N_];
char S[N_];

int group[N_];

int find_group(int x) {
	if (x == group[x]) return x;
	return group[x] = find_group(group[x]);
}

void merge_group(int a, int b) {
	a = find_group(a);
	b = find_group(b);
	if (a != b) group[a] = b;
}

vector<int> pos[N_];
int cnt[N_];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) group[i] = i;

	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);
	for (int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		for (int j = 1; j <= N; j++) if (S[j] == '1') merge_group(i, j);
	}

	for (int i = 1; i <= N; i++) pos[find_group(i)].push_back(P[i]);
	for (int i = 1; i <= N; i++) sort(pos[i].begin(), pos[i].end());

	for (int i = 1; i <= N; i++) {
		int g = find_group(i);
		printf("%d%c", pos[g][cnt[g]++], (i == N) ? '\n' : ' ');
	}


	return 0;
}