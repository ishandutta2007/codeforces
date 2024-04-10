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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll fb[55] = {1, 1};
int ans[55];

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	for(int i = 2; i <= 50; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
	}

	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	k--;
	for(int i = 0; i < n; i++) {
		ans[i] = i + 1 ;
	}
	for(int i = 0; i < n; i++) {
		if(k >= fb[n - i - 1]) {
			swap(ans[i], ans[i + 1]);
			k -= fb[n - i - 1];
			i++;
		}
	}

	for(int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return(0);
}

// by Kim Andrey