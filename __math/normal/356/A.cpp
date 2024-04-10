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
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }


struct P{
	int l,r,a;
	P(){}
	P(int l,int r,int a) : l(l) , r(r), a(a) {}
};

//bool CMP1(const P& x,const P& y){
//	return x.l < y.l;
//}
//
//bool CMP2(const P& x,const P& y){
//	return x.r < y.r;
//}

int l[ten(5) * 3],r[ten(5) * 3],a[ten(5) * 3];
int ans[ten(5) * 3 + 10];

int main(){
	int n,m; cin>>n>>m;
	FOR(i,m) cin>>l[i]>>r[i]>>a[i];

	vector<int> v;
	FOR(i,n) v.push_back(i+1);
	set<int> s(v.begin(),v.end());

	FOR(i,m){
		auto it = s.lower_bound(l[i]);
		while(it != s.end() && *it <= r[i]){
			if(*it == a[i]){
				++it;
			} else {
				ans[*it] = a[i];
				s.erase(it++);
			}
		}
	}

	FOR(i,n) printf("%d%c",ans[i+1],i==n-1?'\n':' ');

	return 0;
}