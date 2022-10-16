#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <bitset>
 
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define forlr(i, l, r) for (int i = (int) l; i <= (int) (r); i++)
#define forrl(i, r, l) for (int i = (int) r; i >= (int) (l); i--)
 
using namespace std;
 
double const pi = 3.14159265358979;
ll const MOD = 1000000007;
ll const LLINF = 1000000000000000000;
int const INF = 1000000000;
 
int const MAXN = 200000;
 
 
 
int a[1000000];
int u[1000000], root[1000000];
 
void dfs(int v) {
	u[v] = 1;
 
	if (u[a[v]] == 0) {
		dfs(a[v]);
	}
	if (u[a[v]] == 1) {
		root[v] = 1;
	}
 
	u[v] = 2;
}
 
 
int main() {
	//freopen("a.in", "rt", stdin);
	//freopen("a.out", "wt", stdout);
 
	int n, m;
 
	scanf("%d", &n);
 
	forn(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}
 
	forn(i, n) {
		if (!u[i]) {
			dfs(i);
		}
	}
	
	int k = -1, res = 0;
 
	forn(i, n) {
		if (root[i]) {
			if (k == -1 || a[i] == i) {
				k = i;
			}
			res++;
		}
	}
 
	if (a[k] == k) {
		res--;
	}
 
	printf("%d\n", res);
 
	forn(i, n) {
		if (root[i]) {
			a[i] = k;
		}
	}
 
	forn(i, n) {
		printf("%d ", a[i] + 1);
	}
 
	return 0;
}