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

typedef struct stbor* bor;
struct stbor {
	bor s[256];
	void init() {
		for(int i = 0; i < 256; i++) {
			s[i] = 0;
		}
	}
};

pair<bool, bool> dfs(bor b, int c = 0) {
	bool wp = c % 2, lp = c % 2, ok = 0;
	for(int i = 0; i < 256; i++) {
		if(b -> s[i]) {
			pair<bool, bool> win = dfs(b -> s[i], c + 1);
			ok = 1;
			if(c % 2 == 0 && win.fs == 1) {
				wp = 1;
			}
			if(c % 2 == 1 && win.fs == 0){
				wp = 0;
			}
			if(c % 2 == 0 && win.sc == 1) {
				lp = 1;
			}
			if(c % 2 == 1 && win.sc == 0){
				lp = 0;
			}
		}
	}
	if(!ok) {wp = c % 2; lp = 1 - c % 2;}
	return(mp(wp, lp));
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	bor b = new stbor; b -> init();
	int n, k;
	scanf("%d%d\n", &n, &k);
	for(int i = 0; i < n; i++) {
		string s; getline(cin, s); int ls = s.length();
		bor h = b;
		for(int i = 0; i < ls; i++) {
			if(!h -> s[s[i]]) {
				bor c = new stbor; c -> init();
				h -> s[s[i]] = c;
			}
			h = h -> s[s[i]];
		}
	}
	
	pair<bool, bool> win = dfs(b);

//	printf("%d %d", win.fs, win.sc);

	if(win.fs && win.sc) {
		printf("First");
	} else 
	if(win.fs && !win.sc) {
		if(k % 2 == 1) {printf("First");} else {printf("Second");}
	} else 
	if(!win.fs && !win.sc) {
//		if(k % 2 == 1) {printf("Second");} else {printf("First");}
		printf("Second");
	} else 
	if(!win.fs && win.sc) {
		printf("Second");
	}
	
	return(0);
}

// by Kim Andrey