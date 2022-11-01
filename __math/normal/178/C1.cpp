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

int table[2 * 100000];
int h,m,n;
map<int,int> mp;

struct OPE{
	bool add;
	int id,hash;
};

int solve(OPE ope)
{
	int ans = 0;
	if(ope.add){
		int i = ope.hash;
		while(table[i]){
			i = (i + m) % h;
			ans++;
		}
		table[i] = true;
		mp[ope.id] = i;
	} else {
		int i = mp[ope.id];
		table[i] = false;
	}
	return ans;
}

int main(){

	cin>>h>>m>>n;
	ll ans = 0;
	FOR(i,n){
		char f[2];
		OPE ope;
		cin >> f;
		ope.add = (f[0] == '+');
		if(ope.add)
			cin >> ope.id >> ope.hash;
		else
			cin >> ope.id;

		ans += solve(ope);
	}

	cout << ans << endl;

	return 0;
}