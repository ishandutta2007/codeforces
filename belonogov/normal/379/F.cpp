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

const int maxn = 1e6 + 100;
const int maxSt = 21;
const int inf = 1e9;

int jump[maxn][maxSt];
int h[maxn];


int getLCA(int v, int u){
	if (h[v] > h[u])
		swap(v, u);
// 	cerr << v << " " << u << endl;
	for (int i = maxSt - 1; i >= 0; i--)
		if (h[jump[u][i]] >= h[v])
			u = jump[u][i];
	assert(h[v] == h[u]);
	if (v == u) return v;
	for (int i = maxSt - 1; i >= 0; i--)
		if (jump[u][i] != jump[v][i]){
			u = jump[u][i];
			v = jump[v][i];			
		}	
	return jump[v][0];		
}

int getLen(int v, int u){
	int t = getLCA(v, u);
	return h[v] + h[u] - h[t] * 2;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int q, n = 4, ans = 2, st = 1, fn = 2, l1, l2, v;
	cin >> q;
	
	h[0] = 0;
	h[1] = h[2] = h[3] = 1;
	for (int i = 0; i < maxSt; i++)
		for (int j = 0; j < 4; j++)	
			jump[j][i] = 0;

		
	for (int i = 0; i < q; i++){
		scanf("%d", &v); v--;
		jump[n][0] = jump[n + 1][0] = v;
		h[n] = h[n + 1] = h[v] + 1;
		for (int j = 1; j < maxSt; j++){
			jump[n][j] = jump[jump[n][j - 1]][j - 1];
			jump[n + 1][j] = jump[jump[n + 1][j - 1]][j - 1];
		}
// 		for (int j = 0; j < n + 2; j++)
// 			cerr << h[j] << " ";
// 		cerr << endl;
		l1 = getLen(n, st);
		l2 = getLen(n, fn);
		if (l1 < l2){
			swap(l1, l2);
			swap(st, fn);			
		}
		
		if (l1 > ans){
			ans = l1;
			fn = n;			
		}
		n += 2;
		printf("%d\n", ans);
	}

	
    return 0;
}