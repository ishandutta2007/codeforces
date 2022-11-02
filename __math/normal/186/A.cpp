#define _USE_MATH_DEFINES
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

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!
typedef pair<double,int> P;

int main(){
	string s,t;
	cin >> s>> t;
	bool ok = false;
	if(sz(s) == sz(t)){
		int x[10000];
		int cnt = 0;
		FOR(i,sz(s)){
			if(s[i] != t[i]){
				x[cnt++] = i;
				if(cnt > 3) break;
			}
		}
		if(cnt == 2 && s[x[0]] == t[x[1]] && s[x[1]] == t[x[0]])
			ok = true;
	}
	cout <<( ok ? "YES" : "NO") << endl;

	return 0;
}