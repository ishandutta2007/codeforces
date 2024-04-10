#undef __USE_MINGW_ANSI_STDIO
#define __USE_MINGW_ANSI_STDIO    1

#include <functional>
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

#define all(a)		(a).begin(), (a).end()

typedef long long int64;

int f() {
	string s;
	getline(cin, s);
	int res = 0;
	for (char c : s) 
		res += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	puts(f() == 5 && f() == 7 && f() == 5 ? "YES" : "NO");
	return 0;
}