#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

int a[100100], tim = 0;
int n, m;

bool pm[100100];

vector<int> vc, rb[100100];

void dfs(int u, int pred = 0) {
	vc.pb(u); a[u] = abs(a[u] - 1);
	pm[u] = 1;
	for(int i = 0; i < rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			dfs(rb[u][i], u);
			vc.pb(u); a[u] = abs(a[u] - 1);
		}
	}

	if(a[u] == 1) {
		if(pred == 0) {
			if(vc.size() > 0) {a[u] = 0; vc.ppb();return;}
/*			for(int i = 0; i < vc.size(); i++) {
				printf("%d ", vc[i]);
			}printf("\n");*/

			printf("-1"); exit(0);
		}
		vc.pb(pred); a[pred] = abs(a[pred] - 1);
		vc.pb(u); a[u] = abs(a[u] - 1);
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		rb[u].pb(v);
		rb[v].pb(u);
	}
	int q = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] == 1) {q = i;}
	}
	if(q == 0) {printf("0");return(0);}
	dfs(q);

	for(int i = 1; i <= n; i++) {if(a[i] == 1) {printf("-1"); exit(0);}}
	printf("%d\n", (int)vc.size());
	for(int i = 0; i < vc.size(); i++) {
		printf("%d ", vc[i]);
	}

     	
	return(0);
}

// by Kim Andrey