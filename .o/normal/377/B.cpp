#include <stdio.h> 
#include <time.h>
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

const int N_ = 100505, M_ = 100505;

struct state {
	int b, c, x;
	state (int b = 0, int c = 0, int x = 0): b(b), c(c), x(x) { }
	bool operator< (const state &s) const { return b < s.b; }
};

int N, M, S;
int A[M_], X[M_], B[N_], C[N_];
state D[N_];
bool cmpX( const int &a, const int &b) { return A[a] < A[b]; }

priority_queue<pii, vector<pii>, greater<pii> > PQ;
int R[N_];

int res = -1, resR[N_];

bool possible (int day) {
	ll sum = 0;
	int d = M, k = -1;
	while(!PQ.empty()) PQ.pop();

	for(int i = M, j = N; i > 0; i--) {
		while(j > 0 && A[i] <= D[j].b) {
			PQ.push ( pii(D[j].c, j) );
			--j;
		}

		if(i > d) { 
			R[X[i]] = D[k].x;
		}else {
			d -= day;
			if(PQ.empty()) return false;

			int w = PQ.top().second; PQ.pop();
			sum += D[w].c; R[X[i]] = D[w].x; k = w; 
			if(sum > S) return false;
		}
	}
	return true;
}

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &M, &S);
	for(i = 1; i <= M; i++) scanf("%d", A+i), X[i] = i;
	for(i = 1; i <= N; i++) scanf("%d", &D[i].b);
	for(i = 1; i <= N; i++) scanf("%d", &D[i].c);
	for(i = 1; i <= N; i++) D[i].x = i;

	sort(X+1, X+M+1, cmpX);
	sort(A+1, A+M+1);
	sort(D+1, D+N+1);

	int low = 1, high = M;
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(possible(mid)) {
			high = mid - 1;
			res = mid;
			for(i = 1; i <= M; i++) resR[i] = R[i];
		}else {
			low = mid + 1;
		}
	}

	if(res == -1) return 0 & puts("NO");
	puts("YES");
	for(i = 1; i <= M; i++) printf("%d ", resR[i]);


	return 0;
}