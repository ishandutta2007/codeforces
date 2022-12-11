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
const double pi = acos(-1.);

ll x[55];

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

	ll n, m;
	cin >> n >> m; m--;
	ll c = (1ll << (n - 2));
	int l = 0, r = n - 1, p = 1;
	while(c > 0) {
		if(m >= c) {
			m -= c;
			x[r] = p;
			r--;
		} else {
			x[l] = p;
			l++;
		}
		c /= 2; p++;
	}
	x[l] = p;
	for(int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}

	return(0);
}

// by Kim Andrey