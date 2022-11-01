#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class Z> bool check(const string &s) {
	if (s == "-0") return true;
	Z r = 0;
	for (int i = 0; i < s.size(); ++i) 
		if (s[i] != '-') r = r * 10 + (s[i] - '0');
	if (s[0] == '-') r = -r;
	if ((r < 0) != (s[0] == '-')) return false;
	string v;
	do v += abs(r % 10) + '0';
	while (r /= 10);
	if (s[0] == '-') v += '-';
	reverse(all(v));
	return v == s;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	string s;
	cin >> s;
	if (check<char>(s)) { puts("byte"); return 0; }
	if (check<short>(s)) { puts("short"); return 0; }
	if (check<int>(s)) { puts("int"); return 0; }
	if (check<long long>(s)) { puts("long"); return 0; }
	puts("BigInteger"); 
	return 0;
}