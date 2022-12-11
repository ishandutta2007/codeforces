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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll hs[10][maxn];
ll deohs[4 * maxn];
ll ch[4 * maxn];
ll basepw[maxn], base = 57;

void push(int v, int tl, int tr) {
	if(ch[v] == -1) {
		return;
	}
	int tm = (tl + tr) >> 1;
	deohs[v * 2 + 1] = hs[ch[v]][tm - tl + 1];
	deohs[v * 2 + 2] = hs[ch[v]][tr - tm];
	ch[v * 2 + 1] = ch[v];
	ch[v * 2 + 2] = ch[v];
	ch[v] = -1;
}

void update(int lf, int rg, int c, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(lf > rg) {
		return;
	}
	if(tl != tr) push(v, tl, tr);
	if(tl == lf && tr == rg) {
		deohs[v] = hs[c][rg - lf + 1];
		ch[v] = c;
		return;
	}
	int tm = (tl + tr) >> 1;
	update(lf, min(rg, tm), c, v * 2 + 1, tl, tm);
	update(max(lf, tm + 1), rg, c, v * 2 + 2, tm + 1, tr);
	deohs[v] = (deohs[v * 2 + 1] * basepw[tr - tm] + deohs[v * 2 + 2]) % mod;
}

ll geths(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(lf > rg) {
		return(0);
	}
	if(tl != tr) push(v, tl, tr);
	if(tl == lf && tr == rg) {
		return(deohs[v]);
	}
	int tm = (tl + tr) >> 1;
	ll L = geths(lf, min(rg, tm), v * 2 + 1, tl, tm);
	ll R = geths(max(lf, tm + 1), rg, v * 2 + 2, tm + 1, tr);
	deohs[v] = (deohs[v * 2 + 1] * basepw[tr - tm] + deohs[v * 2 + 2]) % mod;
	if(rg <= tm) {
		return(L);
	} else
	if(lf > tm) {
		return(R);
	} else {
		return((L * basepw[rg - tm] + R) % mod);
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	for(int i = 0; i < 4 * maxn; i++) {
		ch[i] = -1;
	}

	basepw[0] = 1;
	for(int f = 1; f < maxn; f++) {
		basepw[f] =	(basepw[f - 1] * base) % mod;
		for(int i = 0; i < 10; i++) {
			hs[i][f] = (hs[i][f - 1] * base + ('0' + i)) % mod;
		}
	}

	int n, m, k;
	scanf("%d%d%d\n", &n, &m, &k);
	m += k;
	for(int i = 0; i < n; i++) {
		char c = getchar();
		c -= '0';
		update(i, i, c);
	}
	for(; m > 0; m--) {
		int t, l, r, p;
		scanf("%d%d%d%d", &t, &l, &r, &p);
		l--, r--;
		if(t == 1) {
			update(l, r, p);
		} else {
			bool ok = 1;
			int maxp = (r - l + 1) / p;
			maxp--;
			if(geths(l, l + maxp * p - 1) == geths(l + p, l + p + maxp * p - 1)) {
				if((r - l + 1) % p != 0 && geths(l, l + ((r - l + 1) % p) - 1) != geths((r - (r - l + 1) % p) + 1, r)) {
					ok = 0;
				}
			} else {
				ok = 0;
			}
			if(ok == 0) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
		}
	}

	return(0);
}

// by Kim Andrey