#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

struct State
{
	int sod_dividend = 0;
	int sod_quotient = 0;
	int remainder = 0;
	void append(int m, int digit, string* ret = nullptr);
};

void State::append(int m, int digit, string* ret)
{
	assert(digit >= 0 && digit < 10);
	sod_dividend += digit;
	int e = remainder * 10 + digit;
	if (ret != nullptr) *ret += (char)('0' + e / m);
	sod_quotient += e / m;
	remainder = e % m;
}
string build(int m, int length, int suffix)
{
	string ret;
	State state;
	state.append(m, 1, &ret);
	REP(i, length) state.append(m, 0, &ret);
	state.append(m, suffix / 100, &ret);
	state.append(m, suffix / 10 % 10, &ret);
	state.append(m, suffix % 10, &ret);
	return ret;
}

int sod(int m)
{
	return (m == 0) ? 0 : (sod(m / 10) + m % 10);
}
string trim(string s)
{
	int p = 0;
	for (; s[p] == '0'; ++p);
	return s.substr(p);
}
string solve(int m)
{
	if (sod(m) == 1) return "-1";
	for (int d = 1; d <= 100000; d++) if (sod(d) == sod(d * m) * m) return to_string(d);
	State state;
	state.append(m, 1);
	int eval1 = 1000000000;
	int length1 = -1;
	int suffix1 = -1;
	int eval2 = 1000000000;
	int length2 = -1;
	int suffix2 = -1;
	if (m == 999) return trim(build(m, 80913, 998));
	REP(length, 40000)
	{
		REP(suffix, m)
		{
			State new_state = state;
			new_state.append(m, suffix / 100);
			new_state.append(m, suffix / 10 % 10);
			new_state.append(m, suffix % 10);
			if (new_state.remainder != 0) continue;
			int eval = new_state.sod_dividend * m - new_state.sod_quotient;
			if (eval == 0) return trim(build(m, length, suffix));
			if (eval > 0 && eval < eval1)
			{
				eval1 = eval;
				length1 = length;
				suffix1 = suffix;
			}
			if (eval < 0 && -eval < eval2)
			{
				eval2 = -eval;
				length2 = length;
				suffix2 = suffix;
			}
			if (length1 >= 0 && length2 >= 0)
			{
				int64 length = (int64)eval1 * (length2 + 3) + (int64)eval2 * (length1 + 3);
				if (length <= 500000)
				{
					string s1 = build(m, length1, suffix1);
					string s2 = build(m, length2, suffix2);
					string ret;
					REP(i, eval2) ret += s1;
					REP(i, eval1) ret += s2;
					return trim(ret);
				}
			}
		}
		state.append(m, 0);
	}
	return "-1";
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int m;
	while (cin >> m)
	{
		string ret = solve(m);
		printf("%s\n", ret.c_str());
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}