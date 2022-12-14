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

const int M_ = 100505;

int N, M;

struct point {
	int x, y;
	point (int x = 0, int y = 0): x(x), y(y) { }
	bool operator< (const point &p) const { return x != p.x ? x < p.x : y < p.y; }
};


point D[M_];
int res;

point S[M_], T[M_]; int SN, TN;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) scanf("%d%d", &D[i].x, &D[i].y);
	
	sort(D+1, D+M+1);

	res = (N-1)*2;

	if(D[M].x == N && D[M].y == N) res = -1;

	S[1] = point(1, 1); SN = 1;
	for(int i = 1, lx = 0; i <= M && res >= 0 && SN > 0; ) {
		if(lx+1 != D[i].x) S[1].y = N, SN = 1;
		lx = D[i].x;

		TN = 0;
		for(int j = 1, k = i; j <= SN; j++) {
			if(TN > 0 && T[TN].y >= S[j].y) continue;
			while(k <= M && D[k].x == lx && D[k].y < S[j].x) ++k;
			int ly = S[j].x;
			while(lx == D[k].x && S[j].x <= D[k].y && D[k].y < S[j].y) {
				if(ly < D[k].y && (TN == 0 || T[TN].y < D[k].y - 1)) T[++TN] = point(ly, D[k].y-1);
				ly = D[k].y + 1; ++k;
			}
			if(lx == D[k].x) {
				if(ly < D[k].y) T[++TN] = point(ly, D[k].y-1);
			}else {
				if(ly <= N) T[++TN] = point(ly, N);
				break;
			}
		}

		for(int t = 1; t <= TN; t++) S[t] = T[t];
		SN = TN;

		while(i <= M && D[i].x == lx) ++i;
	}

	if(D[M].x != N && SN > 0) S[SN = 1].y = N;

	if(SN == 0 || S[SN].y != N) res = -1;

	printf("%d\n", res);
	return 0;
}