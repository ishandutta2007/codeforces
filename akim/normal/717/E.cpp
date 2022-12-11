#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

int dp[N], cnt[N], f[N];
vector <int> res, a[N];
int n, x, y;

void dfsf(int v, int p = -1) {
	cnt[v] = (f[v] == 0);
	dp[v] = 1;
	for (int i = 0; i < a[v].size(); i++) {
 	 	int to = a[v][i];
 	 	if (to == p) continue;
 	 	dfsf(to, v);
 	 	dp[v] += dp[to];
 	 	cnt[v] += cnt[to];
 	}
}
void dfsn(int v, int p = -1) {
	res.pb(v);
 		
 	
 	for (int i = 0; i < a[v].size(); i++) {
 	 	int to = a[v][i];
 	 	if (to == p) continue;
 	 	if (cnt[to]!=0) {
 	        f[to] = 1 - f[to];
 	 		dfsn(to, v);
 	 		res.pb(v);
 	 		f[v] = 1 - f[v];
        	if (f[to] == 0) {
        	 	res.pb(to);
        	 	res.pb(v);
        	 	f[v] = 1 - f[v];
        	}
	 	}
 	}
 
}
int main () {
 	scanf("%d", &n);
 	for (int i = 1; i <= n; i++) {
 	 	scanf("%d", &f[i]);
 	 	if (f[i] == -1) f[i] = 0;
 	}
 	for (int i = 1; i < n; i++) {
 	 	scanf("%d%d", &x, &y);
 	 	a[x].pb(y);
 	 	a[y].pb(x);
 	}
 	dfsf(1);
 	dfsn(1);     
 	if (f[1] == 0) {
 	 	int to = a[1][0];
 	 	res.pb(to);
 	 	res.pb(1);
 	 	res.pb(to);
 	}

 	for (int i = 0; i < res.size(); i++) 
 		printf("%d ", res[i]);

return 0;
}