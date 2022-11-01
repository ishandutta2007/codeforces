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


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int n,m,x,y;
char s[1000][1001];
int rc[1000][2];

int dp[1000][2][1000];

int main(){

	cin>>n>>m>>x>>y;
	x--;
	FOR(i,n) cin>>s[i];
	FOR(j,m){
		int cnt = 0;
		FOR(i,n) cnt += s[i][j] == '#';
		rc[j][0] = cnt;
		rc[j][1] = n - cnt;
	}

	memset(dp,0x3f,sizeof(dp));

	dp[0][0][0] = rc[0][0];
	dp[0][1][0] = rc[0][1];

	for(int i = 1; i < m; i++){
		FOR(j,2){
			FOR(k,y){
				dp[i][j][k+1] = min(dp[i][j][k+1],dp[i-1][j][k] + rc[i][j]);
				if(k >= x){
					dp[i][j^1][0] = min(dp[i][j^1][0],dp[i-1][j][k] + rc[i][j^1]);
				}
			}
		}
	}

	int ans = INF;
	FOR(i,2) for(int j = x; j < y; j++){
		ans = min(ans,dp[m-1][i][j]);
	}

	cout << ans << endl;

	return 0;
}