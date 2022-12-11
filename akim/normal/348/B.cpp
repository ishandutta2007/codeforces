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
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef pair<int, int> pii;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

unsigned long long x[100100], y[100100], z[100100] = {1}, kd[100100], sumall = 0;
bool pm[100100] = {0}, lst[100100] = {0};

vector<int> rb[100100];

long long nod(long long a, long long b) {
	while(a > 0){
		b %= a;
		swap(a, b);
	}
	return(b);
}

long long nok(long long a, long long b) {
	return(a * (b / nod(a,b)));
}
void dfs(int u) {
	int i;
	pm[u] = 1;
	lst[u] = 1;
	y[u] = 1;
	for(i = 0; i < rb[u].size(); i++) {
		if(!pm[rb[u][i]]) {
			kd[u]++;
			lst[u] = 0;
			dfs(rb[u][i]);
			y[u] = nok(y[u], y[rb[u][i]] * kd[rb[u][i]]);
			if(y[u] > 10000000000000ll) {cout<<sumall;exit(0);}
		}
	}
	kd[u] = lst[u] ? 1 : kd[u];
}
void vost(int u) {
	int i;
	pm[u] = 0;
	for(i = 0; i < rb[u].size(); i++) {
		if(pm[rb[u][i]]) {
			z[rb[u][i]] = z[u] * (y[u] / (y[rb[u][i]] * kd[rb[u][i]]));
			vost(rb[u][i]);
		}
	}
}
int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	int n, i;
	cin>>n;
	for(i = 0; i < n; i++) {
		cin>>x[i];
		sumall += x[i];
	}

	for(i = 1; i < n; i++) {
		int u, v;
		cin>>u>>v;u--;v--;
		rb[u].pb(v);rb[v].pb(u);
	}
	
	dfs(0);

	vost(0);
	unsigned long long k = 1000000000000000ll;
	for(i = 0; i < n; i++) {
		if(lst[i]) {
			k = min(k, x[i] / z[i]);
		}
	}

	unsigned long long otv = 0;

	for(i = 0; i < n; i++) {
		if(lst[i]) {
			otv += x[i] - k * z[i];
		}
	}
	cout<<otv;
	return 0;
}