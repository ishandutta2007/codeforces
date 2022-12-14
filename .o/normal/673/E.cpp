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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int K_ = 55;
const int N_ = 200500;

int N, K, T[N_];

lf sumT[N_], suminvT[N_], sumU[N_], prec[N_];

struct line {
	lf a, b;
	line (lf a = 0, lf b = 0): a(a), b(b) { }
};

namespace CHT {
	line lines[N_];
	int l, r;

	void clear() {
		l = r = 0;
	}

	void push (lf a, lf b) {
		lines[r] = line(a, b);
		while(l+1 < r && (lines[r-1].b - lines[r-2].b) * (lines[r].a - lines[r-1].a) <= (lines[r-2].a - lines[r-1].a) * (lines[r-1].b - lines[r].b)) {
			lines[r-1] = lines[r];
			r--;
		}
		r++;
	}

	llf get (lf x) {
		while(l+1 < r && (lines[l+1].b - lines[l].b) >= x * (lines[l].a - lines[l+1].a)) ++l;
		return lines[l].a * x + lines[l].b;
	}
};

lf tb[K_][N_];

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++)
		scanf("%d", T+i);

	for(int i = 1; i <= N; i++) {
		sumT[i] = sumT[i-1] + T[i];
		suminvT[i] = suminvT[i-1] + (lf)1.0 / T[i];
		tb[1][i] = sumU[i] = sumU[i-1] + sumT[i] / T[i];
		prec[i] = sumU[i] - sumT[i] * suminvT[i];
	}

	for(int k = 2; k <= K; k++) {
		CHT::clear();
		for(int i = 1; i <= N; i++) {
			tb[k][i] = sumU[i] - CHT::get(suminvT[i]);
			CHT::push(sumT[i], prec[i] - tb[k-1][i]);
		}
	}
	printf("%.25f\n", tb[K][N]);
    return 0;
}