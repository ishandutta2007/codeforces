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
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

struct P{
	int x,y,z;
};

std::istream& operator>>(std::istream& is, P& p){
	return (is >> p.x >> p.y >> p.z);
}


int main(){
	P o,p;
	cin>>o>>p;
	int a[6];
	FOR(i,6) cin>>a[i];

	int ans = 0;
	if(o.y < 0) ans += a[0];
	else if(o.y > p.y) ans += a[1];

	if(o.z < 0) ans += a[2];
	else if(o.z > p.z) ans += a[3];

	if(o.x < 0) ans += a[4];
	else if(o.x > p.x) ans += a[5];

	cout << ans << endl;

	return 0;
}