
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

int n, m;
char s[500][500];
int ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("549A.in", "r", stdin);
	freopen("549A.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", s + i);

	for (int i = 0; i < n - 1; i++) for (int j = 0; j < m - 1; j++) {
		string t;
		for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) t += s[i + x][j + y];
		sort(t.begin(), t.end());
		if (t == "acef") ++ans;
	}

	printf("%d\n", ans);

	return 0;
}