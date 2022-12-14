
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

const int N_ = 1001000;
int N;

struct point {
	int x, y, w;
	point(int x = 0, int y = 0, int w = 0) :x(x), y(y), w(w) { }
	bool operator < (const point &p) const {
		return x / 1000 != p.x / 1000 ? x < p.x : y < p.y;
	}
}D[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("576C.in", "r", stdin);
	freopen("576C.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &D[i].x, &D[i].y);
		D[i].w = i;
		if ((D[i].x / 1000) % 2 == 0) D[i].y = 1000000 - D[i].y;
	}
	sort(D + 1, D + N + 1);
	for (int i = 1; i <= N; i++) printf("%d ", D[i].w);
	return 0;
}