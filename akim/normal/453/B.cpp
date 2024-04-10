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

int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

pair<int, pair<int, int> > x[110];

int bo[110], oo = mod;

int n, mm[62];

void rek(int k, int c, int mask, int raz) {
	if(raz > oo) {return;}
	if(k == n) {
		if(raz < oo) {
			for(int i = 0; i < n; i++) {
				bo[x[i].sc.fs] = x[i].sc.sc;
			}
			oo = raz;
		}
		return;
	}
	for(int i = c; i < 61; i++) {
		if((mm[i] & mask) == 0) {
			x[k].sc.sc = i;
			rek(k + 1, i, (mask | mm[i]), raz + abs(x[k].fs - i));
		}
	}
}

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	for(int i = 1; i < 61; i++) {
		int st = 1;
		for(int f = 0; f < 18; f++, st <<= 1) {
			if(i % pr[f] == 0) {
				mm[i] |= st;
			}
		}
	}
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		x[i].sc.fs = i;
		scanf("%d", &x[i].fs);
	}

	sort(&x[0], &x[n]);

	int raz = 0;
	for(int i = 0; i < n - 18; i++) {
		x[i].sc.sc = 1;
          raz += x[i].fs - 1;
	}

	rek(max(0, n - 18), 1, 0, raz);

	for(int i = 0; i < n; i++) {
		printf("%d ", bo[i]);
	}
	
	return(0);
}

// by Kim Andrey