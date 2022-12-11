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
const int maxn = 100100;

map<int, int> ma[5];
int x[maxn][5];
int n, m, k;
int len = 0, ans[5] = {0};

int check(int u) {
	int z[5] = {0};
	for(int i = 0; i < m; i++) {
		z[i] = max(x[u][i], ma[i].size() > 0 ? ma[i].rbegin() -> fs : 0);
	}
	return(z[0] + z[1] + z[2] + z[3] + z[4]);
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

	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < m; f++) {
			scanf("%d", &x[i][f]);
		}
	}
	int f = 0;
	for(int i = 0; i < n; i++) {
		if(f < i) f = i;
		while(f < n && check(f) <= k) {
			for(int g = 0; g < m; g++)
				ma[g][x[f][g]]++;
			f++;
		}
		if(f - i > len) {
			len = f - i;
			for(int g = 0; g < m; g++) {
				ans[g] = ma[g].size() > 0 ? ma[g].rbegin() -> fs : 0;
			}
		}
		for(int g = 0; g < m; g++) {
			if(--ma[g][x[i][g]] <= 0) {
				ma[g].erase(x[i][g]);
			}
		}
	}
	for(int f = 0; f < m; f++) {
		printf("%d ", ans[f]);
	}

	return(0);
}

// by Kim Andrey