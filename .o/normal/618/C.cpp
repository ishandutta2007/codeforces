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


const int N_ = 100500;
int N;
struct point {
	ll x, y; int p;
	point (ll x = 0, ll y = 0, int p = 0): x(x), y(y), p(p) { }
};

point D[N_];

ll sq(ll v){ return v*v; }
ll dist (point a, point b) { return sq(a.x - b.x) + sq(a.y - b.y); }

ll ccw (point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld%lld", &D[i].x, &D[i].y);
		D[i].p = i;
		if(D[i].x < D[1].x || (D[i].x == D[1].x && D[i].y < D[1].y)) {
			swap(D[i], D[1]);
		}
	}

	sort(D+2, D+N+1, [&](const point &a, const point &b) { 
		return ccw(D[1], a, b) ? ccw(D[1], a, b) > 0 : dist(D[1], a) < dist(D[1], b);
	});

	for(int i = 4; i <= N && ccw(D[1], D[2], D[3]) == 0; i++) {
		swap(D[3], D[i]);
	}

	printf("%d %d %d\n", D[1].p, D[2].p, D[3].p);
    return 0;
}