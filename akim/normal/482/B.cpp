#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

uint t[32][100100];
bool x[100100];
uint z[2 * 131072], k = 131072;
struct zp {
	uint l, r, q;
} zap[100100];

uint getand(uint l, uint r) {
	l += k; r += k;
	uint o = z[l];
	while(l < r) {
		if(l & 1 == 1) {
			o &= z[l];
			l++;
		}
		if(!(r & 1)) {
			o &= z[r];
			r--;
		}
		l >>= 1; r >>= 1;
	}
	if(l == r) {
		o &= z[l];
	}
	return(o);
}

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	uint n, m; scanf("%d%d", &n, &m);
	for(uint i = 0; i < m; i++) {
		scanf("%d%d%d", &zap[i].l, &zap[i].r, &zap[i].q); zap[i].l--, zap[i].r--;
		uint c = 1;
		for(uint f = 0; f < 32; f++, c <<= 1) {
			if(zap[i].q & c) {
				t[f][zap[i].l] += 1;
				t[f][zap[i].r + 1] -= 1;
			}
		}
	}
	uint sum[32] = {0};
	for(uint i = 0; i < n; i++) {
		uint X = 0, c = 1;
		for(uint f = 0; f < 32; f++, c <<= 1) {
			sum[f] += t[f][i];
			if(sum[f]) {
				X |= c;
			}
		}
		z[k + i] = X;
	}
	for(uint i = k - 1; i > 0; i--) {
		z[i] = (z[i * 2] & z[i * 2 + 1]);
	}

	bool ok = 1;
	for(uint i = 0; i < m; i++) {
		if(getand(zap[i].l, zap[i].r) != zap[i].q) {
			ok = 0;
			break;
		}
	}

	if(ok) {
		printf("YES\n");
		for(uint i = 0; i < n; i++) {
			printf("%d ", z[k + i]);
		}
	} else {
		printf("NO\n");
	}

	return(0);
}

// by Kim Andrey