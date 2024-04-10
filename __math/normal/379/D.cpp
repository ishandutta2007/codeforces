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
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct P{
	char l, r;
	ll cnt;
	P(){}
	P(char l, char r, ll cnt) : l(l), r(r), cnt(cnt) {}
};

int k, x, n, m;

P concat(const P& s2, const P& s1){
	P ret;
	ret.l = s2.l;
	ret.r = s1.r;
	ret.cnt = s1.cnt + s2.cnt + ((s2.r == 'A' && s1.l == 'C') ? 1 : 0);
	if (ret.cnt > x) ret.cnt = x + 1;
	return ret;
}

ll sim(P s2, P s1){
	for (int ck = 2; ck < k; ck++){
		P tmp = s1;
		s1 = concat(s2, s1);
		s2 = tmp;
	}
	return s1.cnt;
}

vector<P> gen(int len){
	vector<P> ret;
	int loop;
	loop = max((len - 1) / 2, 0) + 1;
	FOR(i, loop) ret.emplace_back('A', 'A', i);
	if (len == 2){
		ret.emplace_back('A', 'C', 1);
	} else if(len > 3){
		loop = max(len / 2, 0) + 1;
		FOR(i, loop) ret.emplace_back('A', 'C', i);
	}
	loop = max((len - 1) / 2, 0) + 1;
	if (len >= 2) FOR(i, loop) ret.emplace_back('A', 'X', i);
	loop = max((len - 2) / 2, 0) + 1;
	if (len >= 2) FOR(i, loop) ret.emplace_back('C', 'A', i);
	loop = max((len - 1) / 2, 0) + 1;
	FOR(i, loop) ret.emplace_back('C', 'C', i);
	loop = max((len - 2) / 2, 0) + 1;
	if (len >= 2) FOR(i, loop) ret.emplace_back('C', 'X', i);
	loop = max((len - 2) / 2, 0) + 1;
	if (len >= 2) FOR(i, loop) ret.emplace_back('X', 'A', i);
	loop = max((len - 1) / 2, 0) + 1;
	if (len >= 2) FOR(i, loop) ret.emplace_back('X', 'C', i);
	loop = max((len - 2) / 2, 0) + 1;
	FOR(i, loop) ret.emplace_back('X', 'X', i);
	return ret;
}

string to_string(const P& p,int len){
	string s;
	s.push_back(p.l);
	if (len == 1) return s;
	ll tmp = p.cnt;
	for (int i = 1; i < len - 1; i++){
		if (tmp){
			if (s.back() == 'A') s.push_back('C'),tmp--;
			else s.push_back('A');
		}
		else s.push_back('X');
	}
	s.push_back(p.r);
	return s;
}


int main(){
	cin >> k >> x >> n >> m;

	vector<P> vr = gen(n),vl = gen(m);

	for (auto r : vr){
		for (auto l : vl){
			ll cnt = sim(r, l);
			if (cnt == x){
				cout << to_string(r, n) << endl;
				cout << to_string(l, m) << endl;
				return 0;
			}
		}
	}

	puts("Happy new year!");
	return 0;
}