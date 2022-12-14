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
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 70050;
const int S_ = 70050;

int N, S;
int A[N_];
vector<int> pos[S_]; int P[N_], Q[N_];
// P[] = , Q[] =  (stable sort)

bool selected[N_]; // sum = S

const int LG2MOD = 1931;
int lg2[LG2MOD];

vector<uint> tb[2];
int rev[S_];

int main() {
	{
		uint p = 1;
		for(int i = 0; i <= 32; i++) {
			lg2[p] = i;
			p = p * 2; p %= LG2MOD;
		}	
	}

	scanf("%d%d", &N, &S);
	for(int i = 1; i <= N; i++) {
		int &a = A[i]; scanf("%d", &a);
		if(a > S) return 0 & puts("-1");
		pos[a].push_back(i);
	}
	sort(A+1, A+N+1);

	if(N == 1) {
		if(A[1] == S) printf("%d 0\n",A[1]);
		else puts("-1");
		return 0;
	}

	for(int a = 1, c = 0; a <= S; a++) {
		for(auto i : pos[a]) {
			++c;
			P[c] = i;
			Q[i] = c;
		}
	}

	S -= A[N]; //   
	pos[A[N]].pop_back();

	selected[N] = true;
	selected[0] = true;

	tb[0].resize(1); tb[0][0] = 1; rev[0] = 0;
	for(int v = 1; v <= S; v++) rev[v] = (int)1e9;

	for(int i = 1, sum = 0; i <= N-1; i++) {
		int a = A[i];
		int block = a >> 5, shift = a & 31;
		vector<uint> &cur = tb[i&1], &prv = tb[~i&1];

		sum = min(sum + a, S);
		cur.resize((sum >> 5) + 2);
		fill(cur.begin(), cur.end(), false);

		uint carry = 0;

		for(int j = 0; j < cur.size(); j++) {
			if(j < prv.size()) cur[j] = prv[j];
			if(j >= block && j - block < prv.size()) {
				cur[j] |= (prv[j - block] << shift) | carry;
				if(shift > 0) carry = prv[j - block] >> (32 - shift);
			}
		}

		for(int j = 0; j < cur.size(); j++) {
			uint p = cur[j] ^ ((j < prv.size()) ? prv[j] : 0);
			while(p > 0) {
				uint l = p & -p;
				int r = (j << 5) | lg2[l % LG2MOD];
				if(r <= S) {
					assert(rev[r] == (int)1e9);
					rev[r] = i;
				}
				p ^= l;
			}
		}
	}

	bool found = false;

	if(rev[S] < (int)1e9) {
		found = true;
		
		for(int i = N-1, v = S; i > 0 && v > 0; i--) {
			int a = A[i];
			if(v - a >= 0 && rev[v - a] <= i-1) {
				selected[i] = true;
				v -= a;
			}
		}

		for(int j = 1; j <= N; j++) {
			int i = Q[j];
			if(selected[i - 1]) {
				printf("%d 0\n", A[i]);
			}else {
				printf("%d 1 %d\n", A[i] - A[i-1], P[i-1]);
			}
		}
	}else {
		puts("-1");
	}
    return 0;
}