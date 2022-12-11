#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 2000;

vector<int> rb[maxn];
int cnt, n;
int u[maxn], v[maxn], cap[maxn];
int cur[maxn];
int q[maxn], qs, qi;
int d[maxn];
int ans[maxn][maxn];

void add(int uu, int vv, int cp) {
	u[cnt] = uu;
	v[cnt] = vv;
	cap[cnt] = cp;
	rb[uu].pb(cnt++);
	u[cnt] = vv;
	v[cnt] = uu;
	cap[cnt] = 0;
	rb[vv].pb(cnt++);
}

bool bfs() {
	qs = 1;
	qi = 0;
	q[0] = 0;
	for(int i = 0; i < n; i++) {
		d[i] = 0;
	}
	d[0] = 1;
	for(; qi < qs; qi++) {
		int u = q[qi];
		for(int i = 0; i < (int)rb[u].size(); i++) {
			if(d[v[rb[u][i]]] == 0 && cap[rb[u][i]] > 0) {
				d[v[rb[u][i]]] = d[u] + 1;
				q[qs++] = v[rb[u][i]];
			}
		}
	}
	return(d[n - 1] != 0);
}

int dfs(int u, int flow) {
	if(!flow) return(0);
	if(u == n - 1) return(flow);
	for(; cur[u] < (int)rb[u].size(); cur[u]++) {
		if(d[u] + 1 != d[v[rb[u][cur[u]]]]) {
			continue;
		}
		int pushed = dfs(v[rb[u][cur[u]]], min(flow, cap[rb[u][cur[u]]]));
		if(pushed) {
			cap[rb[u][cur[u]]] -= pushed;
			cap[rb[u][cur[u]] ^ 1] += pushed;
			return(pushed);
		}
	}
	return(0);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int m, s = 0, t = 0, nn;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		add(0, i, x);
		t += x;
	}
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		add(n + i, 2 * n + 1, x);
		s += x;
	}
	if(s != t) {
		printf("NO\n");
		return(0);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, n + v, mod);
		add(v, n + u, mod);
	}
	for(int i = 1; i <= n; i++) {
		add(i, n + i, mod);
	}
	nn = n;
	n = n * 2 + 2;
	while(bfs()) {
		for(int i = 0; i < n; i++) {
			cur[i] = 0;
		}
		while(int  flow = dfs(0, mod)) {
			s -= flow;
		}
	}

	if(s == 0) {
		printf("YES\n");
		for(int i = 0; i < cnt; i += 2) {
//			cout << u[i] << " " << v[i] << " " << cap[i] << endl;
			if(u[i] > 0 && u[i] <= nn && v[i] > nn && v[i] <= nn * 2) {
				ans[u[i]][v[i] - nn] += mod - cap[i];
			}
		}
		for(int i = 1; i <= nn; i++) {
			for(int f = 1; f <= nn; f++) {
				printf("%d ", ans[i][f]);
			}
			printf("\n");
		}
	} else {
		printf("NO\n");
	}

	return(0);
}

// by Kim Andrey