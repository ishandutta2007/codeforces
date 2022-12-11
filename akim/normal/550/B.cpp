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
const int maxn = 100100;

int c[maxn];

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

	int n, l, r, x;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for(int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	int mm = 1 << n, ans = 0;
	for(int i = 0; i < mm; i++) {
		int cnt = 0, sum = 0, mx = 0, mn = mod;
		{
			int m = i;
			for(int i = 0; i < n; i++) {
				if(m & (1 << i)) {
					sum += c[i];
					mx = max(mx, c[i]);
					mn = min(mn, c[i]);
					cnt++;
				}
			}
		}
		if(cnt < 2 || mx - mn < x || sum < l || sum > r) {

		} else {
			ans++;
		}
	}

	printf("%d", ans);

	return(0);
}

// by Kim Andrey