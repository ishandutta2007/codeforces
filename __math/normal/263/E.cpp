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

int src[1000][1000]; 
int n,m,k;

ll ld_to_ru[2010][2010];
ll lu_to_rd[2010][2010];
ll ans[2010][2010];

void init(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,n) FOR(j,m) scanf("%d",src[i] + j);
}

void init2(){
	for(int a = k; a < n + k; a++) for(int b = k; b < m + k; b++){
		ll c = src[a-k][b-k];

		ld_to_ru[a-k][b+1] += -c;
		ld_to_ru[a][b-k+1] += c;
		ld_to_ru[a][b+k+1] += -c;
		ld_to_ru[a+k][b+1] += c;

		lu_to_rd[a-k+1][b+1] += -c;
		lu_to_rd[a+1][b-k+1] += -c;
		lu_to_rd[a+1][b+k+1] += c;
		lu_to_rd[a+k+1][b+1] += c;
	}
}

void calc(){
	//leftdown to rightup
	for(int a = 2009; a > 0; a--) for(int b = 0; b < 2009; b++){
		ld_to_ru[a-1][b+1] += ld_to_ru[a][b];
	}

	//leftup to rightdown
	for(int a = 0; a < 2009; a++) for(int b = 0; b < 2009; b++){
		lu_to_rd[a+1][b+1] += lu_to_rd[a][b];
	}

	//2types sum
	FOR(i,2010) FOR(j,2010) ans[i][j] = ld_to_ru[i][j] + lu_to_rd[i][j];

	//up to down
	FOR(a,2009) FOR(b,2010){
		ans[a+1][b] += ans[a][b];
	}

	//left to right
	FOR(a,2010) FOR(b,2009){
		ans[a][b+1] += ans[a][b];
	}
}

Pii get_answer(){
	Pii ret;
	ll cur = -1;
	for(int a = 2 * k - 1; a < n + 1; a++) for(int b = 2 * k - 1; b < m + 1; b++){
		if(cur < ans[a][b]){
			cur = ans[a][b];
			ret.second = b - k + 1;
			ret.first = a - k + 1;
		}
	}

	return ret;
}

int main(){

	init();
	init2();
	calc();
	Pii a = get_answer();

	printf("%d %d\n",a.first,a.second);

	return 0;
}