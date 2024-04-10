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

#define debug(format, ...) printf(format, __VA_ARGS__);

int K, M, N;
const int K_ = 100500, N_ = 100500;

int A[K_];

pii assign[K_];
vector<pii> add[K_];
int type[N_];

ll gcd (ll a, ll b) {
	return b > 0 ? gcd(b, a%b) : a;
}

struct Fraction {
	ll p, q; // p, q
	Fraction (ll p = 1, ll q = 1): p(p), q(q) {
	}
	bool operator< (const Fraction f) const {
		return p * f.q < q * f.p;
		//return p / q < f.p / f.q;
	}
};

vector<pair<Fraction, int>> skills;

int main() {
	scanf("%d%d%d", &K, &N, &M);
	for(int i = 1; i <= K; i++) scanf("%d", A+i);
	for(int s = 1; s <= N; s++) {
		int t, i, b; scanf("%d%d%d", &t, &i, &b);
		type[s] = t;
		if(t == 1) assign[i] = max(assign[i], pii(b, s));
		else if(t == 2) add[i].push_back(pii(b, s));
		else if(t == 3) {
			if(b > 1) skills.push_back(pair<Fraction, int>(Fraction(b-1, 1), s));
		}
	}

	// add
	for(int i = 1; i <= K; i++) {
		if(assign[i].first > A[i]) {
			add[i].push_back(pii(assign[i].first - A[i], assign[i].second));
		}
		sort(add[i].begin(), add[i].end(), greater<pii>());
		ll cur = A[i];
		for(auto it : add[i]) {
			int b = it.first, s = it.second;
			skills.push_back(pair<Fraction, int>(Fraction(b, cur), s));
			cur += b;
		}
	}

	sort(skills.begin(), skills.end(), greater<pair<Fraction, int> >());
	
	M = min(M, (int)skills.size());
	printf("%d\n", M);
	for(int i = 0; i < M; i++) {
		int s = skills[i].second;
		if(type[s] == 1) printf("%d ", s);
	}
	for(int i = 0; i < M; i++) {
		int s = skills[i].second;
		if(type[s] == 2) printf("%d ", s);
	}
	for(int i = 0; i < M; i++) {
		int s = skills[i].second;
		if(type[s] == 3) printf("%d ", s);
	}
    return 0;
}