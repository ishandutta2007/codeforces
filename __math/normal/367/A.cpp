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
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int c[ten(5) + 1][3];

int main(){
	string s; cin >> s;

	FOR(i, sz(s)){
		c[i + 1][0] += c[i][0];
		c[i + 1][1] += c[i][1];
		c[i + 1][2] += c[i][2];
		c[i+1][s[i] - 'x']++;
	}

	int m; cin >> m;
	FOR(i, m){
		int l, r; cin >> l >> r;
		l--;
		if (r - l < 3) puts("YES");
		else {
			int diff[3] = {c[r][0] - c[l][0],c[r][1] - c[l][1],c[r][2] - c[l][2]};
			sort(diff, diff + 3);
			diff[1] -= diff[0];
			diff[2] -= diff[0];
			bool ok = false;
			if ((r - l) % 3 == 0) ok = diff[2] == 0;
			else if ((r - l) % 3 == 1) ok = (diff[1] == 0 && diff[2] == 1);
			else ok = (diff[1] == 1 && diff[2] == 1);

			puts(ok ? "YES" : "NO");
		}

	}

	return 0;
}