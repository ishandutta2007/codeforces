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

const int maxn = 2e5 + 2;
const long long inf = 1e18;

int a[maxn];
vector < int > e[maxn];
vector < int > c[maxn];
long long tree[maxn * 4];
long long upd[maxn * 4];

void push(int v){
	upd[v * 2 + 1] += upd[v];
	upd[v * 2 + 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	tree[v * 2 + 2] += upd[v];
	upd[v] = 0;		
}

void add(int v, int ll, int rr, int l, int r, long long val){
	if (ll >= r || l >= rr)
		return;
	if (l <= ll && rr <= r){
		tree[v] += val;
		upd[v] += val;
		return;
	}
	push(v);
	add(v * 2 + 1, ll, (ll + rr) / 2, l, r, val);
	add(v * 2 + 2, (ll + rr) / 2, rr, l, r, val);
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

long long getmax(int v, int ll, int rr, int l, int r){
	if (ll >= r || l >= rr)
		return -inf;
	if (l <= ll && rr <= r)
		return tree[v];
	push(v);
	return max(getmax(v * 2 + 1, ll, (ll + rr) / 2, l, r), 
			   getmax(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m;
	int l, r, c1;
	long long k;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &l, &r, &c1); l--; r--;
		e[r].pb(r - l + 1);
		c[r].pb(c1);
	}
	add(0, 0, n + 1, 0, n + 1, 0);
	for (int i = 0; i < n; i++){
		k = getmax(0, 0, n + 1, n - i, n + 1);
		add(0, 0, n + 1, n - 1 - i, n - i, k);
		add(0, 0, n + 1, n - i, n + 1, - a[i]);
		for (int j = 0; j < (int)e[i].size(); j++)
			add(0, 0, n + 1, n - 1 - i + e[i][j], n + 1, c[i][j]);
	}
	cout << getmax(0, 0, n + 1, 0, n + 1) << endl;
    return 0;
}