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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")


vector<int> f(string& s){
	vector<int> ret(52);
	FOR(i, sz(s)){
		if ('a' <= s[i] && s[i] <= 'z') {
			ret[s[i] - 'a']++;
		} else {
			ret[s[i] - 'A' + 26]++;
		}
	}
	return ret;
}

int main(){
	string s, t; cin >> s >> t;
	auto a = f(s), b = f(t);
	int fst = 0, scd = 0;
	FOR(i, 52){
		int mn = min(a[i], b[i]);
		a[i] -= mn;
		b[i] -= mn;
		fst += mn;
	}
	FOR(i, 26){
		{
			int mn = min(a[i], b[i+26]);
			a[i] -= mn;
			b[i+26] -= mn;
			scd += mn;
		}
		{
			int mn = min(a[i + 26], b[i]);
			a[i + 26] -= mn;
			b[i] -= mn;
			scd += mn;
		}
	}

	cout << fst << " " << scd << endl;
}