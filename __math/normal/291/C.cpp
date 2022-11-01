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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int ip[ten(5)];

int main(){
	int n,k; cin>>n>>k;
	FOR(i,n){
		int a,b,c,d;
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		ip[i] = (a<<24) + (b<<16) + (c<<8) + d;
	}
	unsigned int ans = 1<<31;
	while(ans != -1){
		set<int> st;
		FOR(i,n) st.insert(ip[i] & ans);
		if(sz(st) == k) break;
		ans = (ans >> 1) | (1 << 31);
	}

	if(ans != -1) printf("%d.%d.%d.%d\n",(ans>>24),(ans>>16)&0xFF,(ans>>8)&0xFF,ans&0xFF);
	else puts("-1");

	return 0;
}