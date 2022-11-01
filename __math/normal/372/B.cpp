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

char s[41][41];

int memo[41][41][41][41];

int main(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, n){
		cin >> s[i];
	}

	FOR(i, n) FOR(j, m){
		for (int h = i; h < n; h++) for (int w = j; w < m; w++){
			if(s[h][w] == '1') continue;
			if (h > i && memo[h][w + 1][i][j] == 0) continue;
			if (w > j && memo[h + 1][w][i][j] == 0) continue;
			memo[h + 1][w + 1][i][j] = 1;
		}
		FOR(h, n) FOR(w, m){
			memo[h + 1][w + 1][i][j] += memo[h + 1][w][i][j] + memo[h][w + 1][i][j] - memo[h][w][i][j];
		}
	}

	FOR(i, q){
		int a, b, c, d;
		scanf("%d%d%d%d", &a,&b,&c,&d);
		int ans = 0;
		a--; b--;
		for (int h = a; h < c; h++){
			for (int w = b; w < d; w++){
				ans += memo[c][d][h][w];
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}