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

int x[5][1100];
vector<int> rb[1100];
int pm[1100];
bool ppm[1100];

void dfs(int u) {
	ppm[u] = 1;
	int ln = 0;
	for(int i = 0; i < rb[u].size(); i++) {
		if(!ppm[rb[u][i]]) {dfs(rb[u][i]);}
		ln = max(ln, pm[rb[u][i]] + 1);
	}
     pm[u] = ln;
//     printf("%d %d\n", u, ln);
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++) {
		for(int f = 1; f <= n; f++) {
			int c; scanf("%d", &c);
			x[i][c] = f;
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int f = i + 1; f <= n; f++) {
			bool ok = 1, rok = 1;
			for(int g = 0; g < k; g++) {
				if(x[g][i] < x[g][f]) {rok = 0;} else {ok = 0;}
			}
				if(ok) {
					rb[i].pb(f);
//					cerr << i <<" " << f <<"\n";
				}
				if(rok) {
					rb[f].pb(i);
//					cerr << f <<" " << i <<"\n";
				}
		}
	}
	
	dfs(0);

	printf("%d", pm[0]);
	
	return(0);
}

// by Kim Andrey