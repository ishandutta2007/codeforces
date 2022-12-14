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

const int N_ = 100500;

char S[N_], T[N_];
int SN, TN;

const int MOD = (int)1e9 + 7;

int pi[N_];
int wh[N_];
bool good[N_];

const int LEAF = 131072;
ll tree[LEAF + LEAF + 5], lazy[LEAF + LEAF+5];

void add(int nd, int nl, int nr, int val) {
	tree[nd] += (ll)val * (nr - nl + 1) % MOD;
	tree[nd] %= MOD;
	lazy[nd] += val;
	lazy[nd] %= MOD;
}

void spread(int nd, int nl, int nr) { if(nl == nr) return;
	int nm = (nl + nr) >> 1;
	add(nd + nd, nl, nm, lazy[nd]);
	add(nd + nd + 1, nm + 1, nr, lazy[nd]);
	lazy[nd] = 0;
}

void upd(int nd, int nl, int nr, int x, int y, int val) {
	if (x > y) return;

	int nm = (nl + nr) >> 1;
	spread(nd, nl, nr);
	if (x <= nl && nr <= y) {
		add(nd, nl, nr, val);
		return;
	}
	if (x <= nm) upd(nd + nd, nl, nm, x, min(y, nm), val);
	if (y > nm) upd(nd + nd + 1, nm + 1, nr, max(x, nm + 1), y, val);
	tree[nd] = (tree[nd + nd] + tree[nd + nd + 1]) % MOD;
}

int get(int nd, int nl, int nr, int x, int y) {
	if (x > y) return 0;

	int nm = (nl + nr) >> 1;
	spread(nd, nl, nr);
	if (x <= nl && nr <= y) {
		return tree[nd];
	}


	ll ret = 0; 
	if (x <= nm) ret += get(nd + nd, nl, nm, x, min(y, nm));
	if (y > nm) ret += get(nd + nd + 1, nm + 1, nr, max(x, nm + 1), y);

	return ret % MOD;

}
int main() {
	scanf("%s%s", S, T);
	SN = strlen(S);
	TN = strlen(T);

	pi[0] = 0;
	for (int i = 1; i < TN; i++) {
		int j = pi[i - 1];
		while (j > 0 && T[i] != T[j]) j = pi[j - 1];
		if (T[i] == T[j]) ++j;
		pi[i] = j;
	}

	memset(wh, -1, sizeof wh);
	for (int i = 0, j = 0; i <= SN; i++, j++) {
		if (j == TN) good[i-TN] = true;
		while (j > 0 && S[i] != T[j]) j = pi[j - 1];
		if (S[i] != T[j]) j = -1;
	}

	for (int i = SN - 1; i >= 0; i--) {
		wh[i] = wh[i + 1];
		if (good[i]) wh[i] = i;
	}

	for (int i = 0; i < SN; i++) {
		int cur = (get(1, 1, LEAF, 1, i) + 1) % MOD;
		if (wh[i] >= 0) upd(1, 1, LEAF, wh[i] + TN, SN, cur);
	}


	printf("%d\n", get(1, 1, LEAF, 1, LEAF));

	return 0;
}