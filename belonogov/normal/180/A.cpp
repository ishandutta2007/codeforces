#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 300;
const int inf = 1e9;

int a[maxn];
vector < pair < int, int > > ans;

void Swap(int v, int u){
	if (v == u)
		return;
	a[u] = a[v];
	a[v] = -1;
	ans.pb(mp(v, u));
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, cur = 0, k, x;
	scanf("%d%d", &n, &m);
	memset(a, -1, sizeof(a));
	for (int i = 0; i < m; i++){
		scanf("%d", &k);
		for (int j = 0; j < k; j++){
			scanf("%d", &x);
			x--;
			a[x] = cur++;;			
		}
	}
	for (int i = 0; i < cur; i++){
		int pos = -1;
		for (int j = 0; pos == -1 && j < n; j++)
			if (a[j] == -1)
				pos = j;
		Swap(i, pos);
		pos = -1;
		for (int j = 0; pos == -1 && j < n; j++)
			if (a[j] == i)
				pos = j;
		
		Swap(pos, i);			
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d\n", ans[i].fr + 1, ans[i].sc + 1);
 
    return 0;
}