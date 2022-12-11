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

int n;
int x[maxn];
int z[maxn];

void dfs(int u, int sum = 0) {
	if(u * 2 + 2 >= n) {z[u] = sum; return;}
	dfs(u * 2 + 1, sum + x[u * 2 + 1]);
	dfs(u * 2 + 2, sum + x[u * 2 + 2]);
	z[u] = max(z[u * 2 + 1], z[u * 2 + 2]);
}
int ans = 0;
void rec(int u, int added = 0) {
	ans += z[0] - (z[u] + added);
	added += z[0] - (z[u] + added);
	if(u * 2 + 2 >= n) {return;}
	rec(u * 2 + 1, added);
	rec(u * 2 + 2, added);
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

	scanf("%d", &n);
	n = (1 << (n + 1)) - 1;
	for(int i = 1; i < n; i++) {
		scanf("%d", &x[i]);
	}

	dfs(0);
	rec(0);

	cout << ans;

	return(0);
}

// by Kim Andrey