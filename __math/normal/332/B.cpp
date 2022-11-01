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
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

ll a[ten(5)*2];


int main(){
	int n,k; cin>>n>>k;
	FOR(i,n) cin>>a[i];
	vector<ll> v;
	{
		ll s = 0;
		FOR(i,n){
			s += a[i];
			if(i+1 >= k){
				v.push_back(s);
				s -= a[i-k+1];
			}
		}
	}

	vector<ll> l(v),r(v);
	vector<int> li(sz(l)),ri(sz(r));
	FOR(i,sz(li)) li[i] = ri[i] = i;
	FOR(i,sz(v)-1){
		if(l[i+1] < l[i]) li[i+1] = li[i];
		l[i+1] = max(l[i],l[i+1]);
	}
	for(int i = sz(v) - 1; i > 0; i--){
		if(r[i-1] < r[i]) ri[i-1] = ri[i];
		r[i-1] = max(r[i-1],r[i]);
	}

	ll mx = 0;
	Pii ans;
	FOR(i,sz(v)){
		if(i+k >= sz(r)) break;
		if(mx < l[i] + r[i+k]){
			mx = l[i] + r[i+k];
			ans = Pii(li[i],ri[i+k]);
		}
	}

	cout << ans.first + 1 << " " << ans.second+1 << endl;


}