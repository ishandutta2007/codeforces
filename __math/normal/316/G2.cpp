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

vector<ull> to_hash(const string& s){
	vector<ull> mp;
	FOR(i,sz(s)){
		ull h = 0;
		for(int j = i; j < sz(s); j++){
			h = s[j] + h * (ull)MOD;
			mp.push_back(h);
		}
	}

	sort(mp.begin(),mp.end());
	return mp;
}

int cont(vector<ull>& con,ull cur){
	pair< vector<ull>::iterator, vector<ull>::iterator > e = equal_range(con.begin(),con.end(),cur);
	return e.second - e.first;
}

int main() { 
	string s;
	int n;
	cin>>s>>n;

	vector<ull> sh = to_hash(s);
	sh.erase(unique(sh.begin(),sh.end()),sh.end());

	FOR(i,n){
		string p;
		int l,r;
		cin>>p>>l>>r;
		vector<ull> new_sh,psh = to_hash(p);
		for(vector<ull>::iterator it = sh.begin(); it != sh.end(); ++it){
			int c = cont(psh,*it);
			if(l <= c && c <= r) new_sh.push_back(*it);
		}
		sh.swap(new_sh);
	}

	cout << sz(sh) << endl;

	return 0;
}