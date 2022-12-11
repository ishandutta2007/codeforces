#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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
const double pi = acos(-1.);
const int maxn = 10 * 100100;

int t1[maxn], t2[maxn], d1[maxn], d2[maxn];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int m;
	scanf("%d", &m);
	int h1, a1, x1, y1;
	scanf("%d%d%d%d", &h1, &a1, &x1, &y1);
	int h2, a2, x2, y2;
	scanf("%d%d%d%d", &h2, &a2, &x2, &y2);

	int tm = 1;
	int b1, c1, b2, c2;
	bool f1 = 1, f2 = 1;
	for(int i = 0; i < maxn - 1; i++) {
		d1[tm] = h1;
		d2[tm] = h2;
		if(t1[h1] == 0) {
			t1[h1] = tm;
		} else {
			if(f1) {
				f1 = 0;
				b1 = h1, c1 = tm - t1[h1];
			}
		}
		if(t2[h2] == 0) {
			t2[h2] = tm;
		} else {
			if(f2) {
				f2 = 0;
				b2 = h2, c2 = tm - t2[h2];
			}
		}
		if(h1 == a1 && h2 == a2) {
			printf("%d\n", tm - 1);
			return(0);
		}
		h1 = (x1 * 1ll * h1 + y1) % m;
		h2 = (x2 * 1ll * h2 + y2) % m;
		tm++;
	}
	if(t1[a1] < t1[b1] || t2[a2] < t2[b2]) {
		printf("-1\n");
		return(0);
	}

	ll ans = t1[a1] - 1;
	int now = t1[a1] - t2[b2];
	while(now < 0) now += c1;
	a2 = t2[a2] - t2[b2];
	for(int i = 0; i < maxn; i++) {
		if(now == a2) {
			printf("%I64d\n", ans);
			return(0);
		}
		now = (now + c1) % c2;
		ans += c1;
	}

	printf("-1\n");


	return(0);
}

// by Kim Andrey