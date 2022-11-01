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
const int MOD = 1000000009; // check!!!
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

int dp[1000 + 10][11][11];

int main(){
	string s; cin>>s;
	int m; cin>>m;
	FOR(i,m+1) FOR(j,11) FOR(k,11) dp[i][j][k] = -1;
	dp[0][0][0] = 0;

	FOR(i,m){
		FOR(j,11) FOR(k,11) if(dp[i][j][k] != -1){
			for(int o = 1; o <= 10; o++) if(s[o-1] == '1'){
				if(o > k && o != j){
					dp[i+1][o][o-k] = j;
				}
			}
		}
	}


	int ak = -1,al;

	FOR(k,11) FOR(l,11)
		if(dp[m][k][l] != -1){
				ak = k,al = l;
		}

	if(ak == -1){
		puts("NO");
		return 0;
	}

	vector<int> ans;
	for(int am = m; am > 0; am--){
		ans.push_back(ak);
		int pl = dp[am][ak][al];
		al = ak - al;
		ak = pl;
	}

	reverse(ans.begin(),ans.end());

	puts("YES");
	FOR(i,m) printf("%d%c",ans[i],i==m-1?'\n':' ');

}