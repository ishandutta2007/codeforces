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
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

int gcd(int x,int y){
	while(x % y != 0){
		int buf = y;
		y = x % y;
		x = buf;
	}
	return y;
}

int main()
{
	int b,d;
	cin>>b>>d;
	if((b-1)%d == 0) cout << "3-type" <<endl;
	else if((b+1)%d == 0) cout << "11-type" << endl;
	else{
		int g;
		int cnt = -1;
		do{
			g = gcd(b,d);
			d /= g;
			cnt++;
		}while(g != 1);

		if(d == 1){
			cout << "2-type" << endl << cnt << endl;
		}
		else {
			int a = (b-1)*(b+1) / gcd(b-1,b+1);
			if(a%d == 0) cout << "6-type" << endl;
			else cout << "7-type" << endl;
		}
	}

	return 0;
}