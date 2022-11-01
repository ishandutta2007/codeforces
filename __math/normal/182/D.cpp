#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define all(c) (c).begin(),(c).end()
#define FILL(c,val) memset((c),val,sizeof(c))

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int gcd(int x,int y){
	while(x % y != 0){
		int buf = y;
		y = x % y;
		x = buf;
	}

	return y;
}

bool candiv(string &s,string &div)
{
	int z = sz(div);
	for(int i = 0; i < sz(s); i++){
		if(s[i] != div[i % z]) return false;
	}
	return true;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int ans = 0;
	int z = gcd(sz(s1),sz(s2));
	for(int i = 1; i <= z; i++){
		if(z % i != 0) continue;
		string div(s1.begin(),s1.begin() + i);
		if(candiv(s1,div) && candiv(s2,div))
			ans++;
	}

	cout << ans << endl;

	return 0;
}