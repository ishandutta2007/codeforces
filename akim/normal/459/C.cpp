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

int avt[5000], uc[1100], x[1100], out[1100];
vector<int> vc[3000];
int n, k, d, nn, dd = 0;

int del(int n, int k) {
	int o = n / k;
	if(n % k) {o++;}
	return(o);
}
void make() {
	int p = 0;
	for(int i = 0; i < n; i++) {
		vc[p].pb(x[i]);
		out[x[i]] = p++;
		p %= k;
	}
	p = 0;
	for(int i = 0; i < 3000; i++) {
		for(int f = 0; f < vc[i].size(); f++) {
			x[p++] = vc[i][f];
		}
		vc[i].clear();
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", out[i] + 1);
	}printf("\n");
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	scanf("%d%d%d", &n, &k, &d); nn = n;
	if(k == 1 && n > 1) {printf("-1"); return(0);}
	while(nn > 1) {
		nn = del(nn, k); dd++;
	}
	
	if(dd > d) {printf("-1"); return(0);}

	for(int i = 0; i < n; i++) {x[i] = i;}
	
	for(; d > 0; d--) {
		make();
	}
	
	return(0);
}

// by Kim Andrey