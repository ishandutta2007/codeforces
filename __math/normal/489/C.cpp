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

typedef pair<string, string> P;
string p[110][910][2];

int main(){
	int m , s; cin >> m >> s;
	if (m == 1 && s == 0) {
		puts("0 0");
		return 0;
	}
	FOR(i, 110) FOR(j, 910) FOR(k,2) p[i][j][k] = "-1";
	p[0][0][0] = p[0][0][1] = "";
	FOR(i, m){
		FOR(j, 901){
			FOR(k, 2){
				if (p[i][j][k] == "-1") continue;
				FOR(l, 10){
					if (p[i][j][k] == "" && l == 0) continue;
					string nxt = p[i][j][k];
					nxt.push_back('0' + l);
					if (p[i + 1][j + l][0] == "-1") p[i + 1][j + l][0] = nxt;
					else p[i + 1][j + l][0] = min(p[i + 1][j + l][0], nxt);
					if (p[i + 1][j + l][1] == "-1") p[i + 1][j + l][1] = nxt;
					else p[i + 1][j + l][1] = max(p[i + 1][j + l][1], nxt);
				}
			}
		}
	}

	printf("%s %s\n",p[m][s][0].c_str(),p[m][s][1].c_str());
}