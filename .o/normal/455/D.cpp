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

const int B = 320;
const int N_ = 100005;
const int Q_ = 100005;

int N, Q;
int C[B+12][N_];
int A[N_];
int bk[B+12][B+B+12], sz[B+12];
int pos[N_];

void find_loc (int x, int &b, int &w) {
	int s = 0;
	for(int i = 0; i < B; i++) {
		if(s + sz[i] > x) {
			b = i;
			w = x - s;
			return;
		}
		s += sz[i];
		//if(sz[i] > 0) b = i, w = sz[i]-1;
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", A+i);
		++C[i/B][A[i]];
		bk[i/B][sz[i/B]++] = i;
	}
	scanf("%d", &Q);

	int lastans = 0;
	while(Q--) {
		int type; scanf("%d", &type);
		if(type == 1) {
			int l,r; scanf("%d%d", &l, &r);
			l = (l + lastans - 1) % N;
			r = (r + lastans - 1) % N;
			if(l > r) swap(l, r);
			// r -> l

			int lb, lw, rb, rw;
			find_loc(l, lb, lw); int lv = bk[lb][lw];
			find_loc(r, rb, rw); int rv = bk[rb][rw];

			for(int i = rw; i+1 < sz[rb]; i++) bk[rb][i] = bk[rb][i+1];
			bk[rb][--sz[rb]] = 0;
			--C[rb][A[rv]];
			
			for(int i = sz[lb]++; i > lw; i--) bk[lb][i] = bk[lb][i-1];
			bk[lb][lw] = rv; 
			++C[lb][A[rv]];
		}else if(type == 2) {
			int l,r,k; scanf("%d%d%d", &l, &r, &k);
			l = (l + lastans - 1) % N;
			r = (r + lastans - 1) % N;
			if(l > r) swap(l, r);
			k = (k + lastans - 1) % N + 1;

			int ret = 0;

			int lb, lw, rb, rw;
			find_loc(l, lb, lw); int lv = bk[lb][lw];
			find_loc(r, rb, rw); int rv = bk[rb][rw];
			
			if(lb == rb) {
				for(int i = lw; i <= rw; i++) if(A[bk[lb][i]] == k) ++ret;
			}else {
				for(int i = lw; i < sz[lb]; i++) if(A[bk[lb][i]] == k) ++ret;
				for(int i = lb+1; i <= rb-1; i++) ret += C[i][k];
				for(int i = 0; i <= rw; i++) if(A[bk[rb][i]] == k) ++ret;
			}

			printf("%d\n", ret);
			lastans = ret;
		}

		if(Q % B == 0) {
			int an = 0;
			for(int i = 0; i < B; i++) {
				for(int j = 0; j < sz[i]; j++) {
					pos[an++] = bk[i][j];
					C[i][A[bk[i][j]]] = 0;
				}
				sz[i] = 0;
			}
			for(int i = 0; i < N; i++) {
				int b = i/B;
				bk[b][sz[b]++] = pos[i];
				++C[b][A[pos[i]]];
			}
		}
	}
	return 0;
}