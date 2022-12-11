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

bool isprime(int u) {
	int sq = sqrt(u) + 1;
	for(int i = 2; i <= sq; i++) {
		if(u % i == 0) {
			return(0);
		}
	}
	return(1);
}

vector<int> prime;

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

	int n;
	scanf("%d", &n);
	if(isprime(n)) {
		printf("%d\n%d", 1, n);
		return(0);
	}

	for(int i = 3; i < 150; i++) {
		if(isprime(i)) {
			prime.pb(i);
		}
	}
	for(int i = 0; i < (int)prime.size(); i++) {
		for(int f = i; f < (int)prime.size(); f++) {
			if(n - prime[i] - prime[f] > 1)
			if(isprime(n - prime[i] - prime[f])) {
				printf("3\n%d %d %d", n - prime[i] - prime[f], prime[i], prime[f]);
				return(0);
			}
		}
	}

	return(0);
}

// by Kim Andrey