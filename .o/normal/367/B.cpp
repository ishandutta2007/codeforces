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

const int N_ = 220005;
const int M_ = 220005;
const int P_ = 220005;

int N, M, P;
int A[N_], B[M_], C[M_], CN;
bool Res[N_]; int RN;
int freq[M_], freqn, cnt[M_], tme[M_];

int main() {
	int i, j, k;
	
	scanf("%d%d%d", &N, &M, &P);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	for(i = 1; i <= M; i++) scanf("%d", B+i), C[i] = B[i];
	
	sort(C+1, C+M+1);
	CN = unique(C+1, C+M+1) - (C+1);

	for(i = 1; i <= M; i++) {
		B[i] = lower_bound(C+1, C+CN+1, B[i]) - C;
		if(++freq[B[i]] == 1) ++freqn;
	}

	for(i = 1; i <= N; i++) {
		int *a = lower_bound(C+1, C+CN+1, A[i]);
		A[i] = (*a == A[i]) ? (a - C) : -1;
	}

	for(i = 1; i <= P; i++) {
		if((ll)i + (ll)(M-1) * P > N) break;
		int w = 0;

		for(j = 0; i + j * P <= N; j++) {
			int x, v;

			if(j >= M) {
				x = i + (j-M) * P;
				v = A[x];
				if(v > 0 && freq[v] > 0) {
					if(tme[v] < i) tme[v] = i, cnt[v] = 0;
					--cnt[v];
					if(cnt[v] == freq[v]) ++w;
					else if(cnt[v] == freq[v]-1) --w;
				}
			}

			x = i + j * P;
			v = A[x];
			if(v > 0 && freq[v] > 0) {
				if(tme[v] < i) tme[v] = i, cnt[v] = 0;
				++cnt[v];
				if(cnt[v] == freq[v]) ++w;
				else if(cnt[v] == freq[v]+1) --w;
			}

			if(j >= M-1 && w == freqn) {
				Res[i + (j-M+1) * P] = true; 
				++RN;
			}
		}
	}

	printf("%d\n", RN);
	for(i = 1; i <= N; i++) if(Res[i]) printf("%d ", i);

	return 0;
}