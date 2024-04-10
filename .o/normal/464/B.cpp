#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll D[8][3];
bool used[8];

ll dsts[100];
bool good() {
	int dn = 0;
	for(int i = 0; i < 8; i++) {
		for(int j = i+1; j < 8; j++) {
			ll d = 0;
			for(int k = 0; k < 3; k++) {
				ll t = D[i][k] -  D[j][k];
				d += t*t;
			}
			dsts[dn++] = d;
		}
	}
	sort(dsts, dsts+dn);
	if(dsts[0] == 0) return 0;

	ll l = dsts[0];
	int cnt[4] = {0,0,0,0};
	for(int i = 0; i < dn; i++) {
		for(int k = 1; k <= 3; k++) if(dsts[i] == l*k) ++cnt[k];
	}

	if(cnt[1] != 12) return 0;
	if(cnt[2] != 12) return 0;
	if(cnt[3] != 4) return 0;
	return 1;
}

void solve (int x) {
	if(x == 8) {
		if(good()) {
			puts("YES");
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 3; j++) printf("%I64d%c", D[i][j], (j == 2) ? '\n' : ' ');
			}
			exit(0);
		}
		return;
	}

	sort(D[x], D[x]+3);
	do {
		solve(x+1);
	}while(next_permutation(D[x], D[x]+3));
}

int main() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 3; j++) scanf("%I64d", &D[i][j]);
	}

	solve(1);


	puts("NO");

	return 0;
}