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

int main(){
	int n; cin>>n;
	vector<int> a(n),b(n);
	FOR(i,n) cin>>a[i];
	FOR(i,n) b[i] = a[i];

	map<int,int> mp;
	FOR(i,n){
		vector<int> c;
		while(a[i]){
			int x = a[i] % 10;
			a[i] /= 10;
			c.push_back(x != 0);
		}
		int f = 0;
		FOR(i,sz(c)) f = f * 2 + c[sz(c) - i - 1];
		mp[f] = b[i];
	}

	vector<int> ans[8];
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		FOR(i,8) if((i & it->first) == 0){
			vector<int> nxt = ans[i];
			nxt.push_back(it->second);
			if(sz(nxt) > sz(ans[i | it->first])){
				ans[i | it->first] = nxt;
			}
		}
	}

	vector<int> out;
	FOR(i,8){
		if(sz(out) < sz(ans[i])){
			out = ans[i];
		}
	}

	cout << sz(out) << endl;
	FOR(i,sz(out)) printf("%d%c",out[i],i==sz(out)-1?'\n':' ');

	return 0;
}