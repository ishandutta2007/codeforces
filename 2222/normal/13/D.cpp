#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n, m;

int xa[512], ya[512], xb[512], yb[512];
__attribute__((aligned(16))) volatile ll t[2]; 
__attribute__((aligned(16))) char f[512][512][64];

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	scanf("%d%d", &n, &m);
	fill(xb + m, xb + 512, -1u/2);
	fill(yb + m, yb + 512, -1u/2);
	REP (i, n) scanf("%d%d", xa + i, ya + i);
	REP (i, m) scanf("%d%d", xb + i, yb + i);
	REP (j, n) REP (i, j) {
		ll A = ya[j] - ya[i], B = xa[i] - xa[j], C = A * xa[i] + B * ya[i];
		char *w = f[i][j];
		for (int q = 0; q < 512; )
			for (int d = 0; d < 32; ++w, d += 8, q += 8) {
				ll x3[] = {xb[q + 0] * A, xb[q + 1] * A, xb[q + 2] * A, xb[q + 3] * A, xb[q + 4] * A, xb[q + 5] * A, xb[q + 6] * A, xb[q + 7] * A};
				ll x4[] = {yb[q + 0] * B, yb[q + 1] * B, yb[q + 2] * B, yb[q + 3] * B, yb[q + 4] * B, yb[q + 5] * B, yb[q + 6] * B, yb[q + 7] * B};
				x4[0] += x3[0], x4[1] += x3[1], x4[2] += x3[2], x4[3] += x3[3];
				x4[4] += x3[4], x4[5] += x3[5], x4[6] += x3[6], x4[7] += x3[7];
				if (x4[0] < C) *w |= 0x01;
				if (x4[1] < C) *w |= 0x02;
				if (x4[2] < C) *w |= 0x04;
				if (x4[3] < C) *w |= 0x08;
				if (x4[4] < C) *w |= 0x10;
				if (x4[5] < C) *w |= 0x20;
				if (x4[6] < C) *w |= 0x40;
				if (x4[7] < C) *w |= 0x80;
			}
	}
	int res = 0;
	REP (j, n) REP (i, j) {
		ll A = ya[j] - ya[i], B = xa[i] - xa[j], C = A * xa[i] + B * ya[i];
		REP (k, i) {
			__asm volatile ("xorpd %xmm0, %xmm0 \n\t");
			if (A * xa[k] + B * ya[k] < C) {
				__asm volatile (
				
					"movdqa 0(%0), %%xmm1 \n\t"
					"movdqa 0(%1), %%xmm2 \n\t"
					"movdqa 0(%2), %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm2 \n\t"
					"andpd %%xmm2, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"
					
					"movdqa 16(%0), %%xmm1 \n\t"
					"movdqa 16(%1), %%xmm2 \n\t"
					"movdqa 16(%2), %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm2 \n\t"
					"andpd %%xmm2, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"
					
					"movdqa 32(%0), %%xmm1 \n\t"
					"movdqa 32(%1), %%xmm2 \n\t"
					"movdqa 32(%2), %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm2 \n\t"
					"andpd %%xmm2, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"
					
					"movdqa 48(%0), %%xmm1 \n\t"
					"movdqa 48(%1), %%xmm2 \n\t"
					"movdqa 48(%2), %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm2 \n\t"
					"andpd %%xmm2, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"
					
					: : "r"(f[i][j]), "r"(f[k][j]), "r"(f[k][i]) :
				);
			} else {
				__asm volatile (
				
					"movdqa 0(%0), %%xmm1 \n\t"
					"movdqa 0(%1), %%xmm2 \n\t"
					"movdqa 0(%2), %%xmm3 \n\t"
					"andnpd %%xmm2, %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"

					"movdqa 16(%0), %%xmm1 \n\t"
					"movdqa 16(%1), %%xmm2 \n\t"
					"movdqa 16(%2), %%xmm3 \n\t"
					"andnpd %%xmm2, %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"
					
					"movdqa 32(%0), %%xmm1 \n\t"
					"movdqa 32(%1), %%xmm2 \n\t"
					"movdqa 32(%2), %%xmm3 \n\t"
					"andnpd %%xmm2, %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"

					"movdqa 48(%0), %%xmm1 \n\t"
					"movdqa 48(%1), %%xmm2 \n\t"
					"movdqa 48(%2), %%xmm3 \n\t"
					"andnpd %%xmm2, %%xmm3 \n\t"
					"andnpd %%xmm3, %%xmm1 \n\t"
					"orpd %%xmm1, %%xmm0 \n\t"

					: : "r"(f[i][j]), "r"(f[k][j]), "r"(f[k][i]) :
				);				
			}
			__asm volatile ( "movdqa %%xmm0, 0(%0) \n\t" : : "r"(t) : );
			if (t[0] == 0 && t[1] == 0) ++res;
		}
	}
	printf("%d\n", res);
	#ifdef LocalHost
	cout << clock() << endl;
	#endif
	return 0;
}