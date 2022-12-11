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

int x[maxn];
bool cyc[maxn], pm[maxn];

ll gcd(ll a, ll b) {
	while(a) {
		b %= a;
		swap(a, b);
	}
	return(b);
}

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

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	ll ans = 1;

	for(int i = 1; i <= n; i++) {
		ll pos = i, len = 0;
		while(!pm[pos]) {
			pm[pos] = 1;
			pos = x[pos];
			len++;
		}
		for(int f = 1; f <= n; f++) {
			pm[f] = 0;
		}
		if(pos != i) {
			continue;
		}
		cyc[i] = 1;
		ans = ans / gcd(ans, len) * len;
	}
	ll mx = 0;
	for(int i = 1; i <= n; i++) {
		ll pos = i, len = 0;
		while(!cyc[pos]) {
			pos = x[pos];
			len++;
		}
		mx = max(mx, len);
	}
	printf("%I64d", max(((mx + ans - 1) / ans) * ans, ans));

	return(0);
}

// by Kim Andrey