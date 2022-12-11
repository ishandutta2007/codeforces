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

int x[maxn];
bool pm[maxn];
int pred[maxn];
int st[maxn];
int h, ans, ansbeg, beg;

void out(int u, bool ok = 1) {
	if(st[pred[u]] == 1 && pred[u] != 0) {h++; out(pred[u], ok);}
	if(ok) {printf("%d ", u);} else {
		if(h > ans) {
			ans = h;
			ansbeg = beg;
		}
	}
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

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &pred[i]);
		st[pred[i]]++;
	}

	for(int i = 1; i <= n; i++) {
		if(x[i]) {
			h = 1;
			beg = i;
			out(i, 0);
		}
	}

	printf("%d\n", ans);
	out(ansbeg);

	return(0);
}

// by Kim Andrey