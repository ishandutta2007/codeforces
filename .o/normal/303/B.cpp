#include <stdio.h>/*
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
*/
//using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

ll N, M, X, Y, A, B, G, T;
ll x1, y1, x2, y2;

ll gcd (ll a, ll b) {
	ll c;
	while(b > 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int i, j, k;

	scanf("%lld%lld%lld%lld%lld%lld", &N, &M, &X, &Y, &A, &B);
	G = gcd(A, B); A /= G; B /= G;

	if(M * A < N * B) T = M / B; else T = N / A;
	A *= T; B *= T;

	x1 = X - (A + 1) / 2;
	y1 = Y - (B + 1) / 2;
	x2 = X + A / 2;
	y2 = Y + B / 2;
	
	bool chk = true;
	do {
		chk = false;
		while(x1 < 0) {
			ll v = -x1;
			x1 += v; x2 += v;
			chk = true;
		}
		while(y1 < 0) {
			ll v = -y1;
			y1 += v; y2 += v;
			chk = true;
		}
		while(x2 > N) {
			ll v = N-x2;
			x1 += v; x2 += v;
			chk = true;
		}
		while(y2 > M) {
			ll v = M-y2;
			y1 += v; y2 += v;
			chk = true;
		}
	} while(chk);

	printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
	
	return 0;
}