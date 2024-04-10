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

const int N_ = (int)1e6 + 5;
int N, M;
char S[N_], T[N_];

vector<int> multiply (vector<int>&p, vector<int>&q) {
	vector<int> ret(N);
	for(int i = 0; i < N; i++) ret[i] = q[p[i]];
	return ret;
}

int main() {
	scanf("%s%d", S, &M); N = strlen(S);
	while(M--) {
		int k, d; scanf("%d%d", &k, &d);
		vector<int> p1(N), p2(N);
		for(int i = 0; i < N; i++) p2[i] = (i+1) % N, p1[i] = i;
		for(int g = 0, p = 0; g < d; g++) {
			for(int i = g; i < k; i += d) p1[p++] = i;
		}
		vector<int> b = multiply(p2, p1);
		vector<int> cur = b, perm(N);
		int rep = N-k+1;
		for(int i = 0; i < N; i++) perm[i] = i;

		while(rep > 0) {
			if(rep & 1) perm = multiply(perm, cur);
			cur = multiply(cur, cur);
			rep >>= 1;
		}

		for(int i = 0; i < N; i++) T[i] = S[perm[i]];
		for(int i = 0; i < N; i++) S[i] = T[i];

		rotate(S, S+(k-1), S+N);
		puts(S);
	}
    return 0;
}