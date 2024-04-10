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
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

map<ull,string> to_sh(const string& s){
	map<ull,string> mp;
	FOR(i,sz(s)){
		ull h = 0;
		string c;
		for(int j = i; j < sz(s); j++){
			h = s[j] + h * (ull)MOD;
			c.push_back(s[j]);
			mp[h] = s[j];
		}
	}

	return mp;
}

map<ull,int> to_hash(const string& s){
	map<ull,int> mp;
	FOR(i,sz(s)){
		ull h = 0;
		for(int j = i; j < sz(s); j++){
			h = s[j] + h * (ull)MOD;
			mp[h]++;
		}
	}

	return mp;
}

int cont(map<ull,int>& con,ull cur){
	if(con.find(cur) == con.end()) return 0;
	else return con[cur];
}

int main() { 
	string s;
	int n;
	cin>>s>>n;

	map<ull,int> sh = to_hash(s);

	FOR(i,n){
		string p;
		int l,r;
		cin>>p>>l>>r;
		map<ull,int> new_sh,psh = to_hash(p);
		for(map<ull,int>::iterator it = sh.begin(); it != sh.end(); ++it){
			int c = cont(psh,it->first);
			if(l <= c && c <= r) new_sh[it->first] = it->second;
		}
		sh = new_sh;
	}

	int ans = 0;
	for(map<ull,int>::iterator it = sh.begin(); it != sh.end(); ++it){
		ans++;
	}

	cout << ans << endl;

	return 0;
}