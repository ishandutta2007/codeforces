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

ll a[maxn], nxt[maxn], cnt[maxn], end[maxn];

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

	ll n, q, S = 0;
	scanf("%I64d%I64d", &n, &q);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		S += a[i];
	}

	for(; q > 0; q--) {
		ll qq;
		scanf("%I64d", &qq);
		if(S <= qq) {
			printf("1\n");
			continue;
		}
		int f = 0;
		ll sum = 0;
		for(int i = 0; i < n; i++) {
			while(sum + a[f] <= qq) {
				sum += a[f];
				f = (f + 1) % n;
			}
			nxt[i] = f;
			sum -= a[i];
		}
		for(int i = n - 1; i >= 0; i--) {
			if(nxt[i] < i) {
				end[i] = nxt[i];
				cnt[i] = 1;
			} else {
				end[i] = end[nxt[i]];
				cnt[i] = cnt[nxt[i]] + 1;
			}
		}
		ll ans = n;
		for(int i = 0; i <= nxt[0]; i++) {
			ans = min(ans, cnt[i] + (i > end[i]));
		}
		printf("%I64d\n", ans);
	}

	return(0);
}

// by Kim Andrey