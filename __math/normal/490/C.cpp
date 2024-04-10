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


bool ok[ten(6) + 1];

int main(){
	string s;
	int a, b; cin >> s >> a >> b;
	memset(ok, 1, sizeof(ok));
	{
		int cur = 0;
		FOR(i, sz(s)-1){
			cur = (cur * 10 + s[i] - '0') % a;
			ok[i] = cur == 0;
		}
	}
	{
		int p = 1;
		int cur = 0;
		FOR(i, sz(s)-1){
			cur = (cur + (s[sz(s)-1-i] - '0') * p) % b;
			ok[sz(s)-i-2] &= cur == 0;
			p = p * 10 % b;
		}
	}
	FOR(i, sz(s)-1){
		if (!ok[i] || s[i+1] == '0') continue;
		cout << "YES" << endl;
		cout << s.substr(0, i + 1) << endl;
		cout << s.substr(i+1, sz(s) - (i + 1)) << endl;
		return 0;
	}
	puts("NO");
}