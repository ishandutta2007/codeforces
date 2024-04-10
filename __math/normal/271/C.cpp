#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool prime[1000001]; //10^6

//f
void init_prime()
{
	memset(prime,1,sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i < sizeof(prime); i++) if(prime[i])
		for(int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
}


int main(){
	int n,k;
	cin>>n>>k;

	if(n < 3*k){
		puts("-1");
		return 0;
	}

	for(int i = 0; i < k; i++){
		printf("%d %d ",i+1,i+1);
	}
	for(int i = 0; i < k; i++){
		printf("%d%c",i+1,i+2*k == n-1? '\n' : ' ');
	}
	for(int i = 3*k; i < n; i++){
		printf("1%c",i == n-1? '\n' : ' ');
	}

	return 0;
}