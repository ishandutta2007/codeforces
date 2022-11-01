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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int n;
int a[3];

int dp[301][301][301];

int dfs3(int x,int y,int z){
	if(x >= 128) return dp[x][y][z] = true;
	if(dp[x][y][z] != -1) return dp[x][y][z];
	if(x == 0){
		return dp[x][y][z] = y != z;
	} else {
		if(x + y < z) return dp[x][y][z] = true; 
		for(int i = x; i > 0; i--){
			if(!dfs3(x-i,y-i,z-i)) return dp[x][y][z] = true;
		}
		for(int i = x; i > 0; i--){
			if(!dfs3(x-i,y,z)) return dp[x][y][z] = true;
		}
		for(int i = y; i > 0; i--){
			if(x > y-i){
				if(!dfs3(y-i,x,z)) return dp[x][y][z] = true;
			}else {
				if(!dfs3(x,y-i,z)) return dp[x][y][z] = true;
			}
		}
		for(int i = z; i > 0; i--){
			if(x > z-i){
				if(!dfs3(z-i,x,y)) return dp[x][y][z] = true;
			}
			else if(y > z-i){
				if(!dfs3(x,z-i,y)) return dp[x][y][z] = true;
			}else {
				if(!dfs3(x,y,z-i)) return dp[x][y][z] = true;
			}
		}
	}

	return false;
}

bool dp2[1000];
vector<Pii> vp2;

void init2(){
	int cnt = 0;
	for(int i = 0;i <= 300; i++){
		if(!dp2[i] && !dp2[i+cnt]){
			dp2[i] = dp2[i+cnt] = true;
			vp2.push_back(Pii(i,i+cnt));
			cnt++;
		}
	}
}

int main(){
	init2();

	memset(dp,-1,sizeof(dp));
	//for(int i = 0; i <= 300; i++){
	//	for(int j = i; j <= 300; j++){
	//		for(int k = j; k <= 300; k++){
	//			int ans = dfs3(i,j,k);
	//			if(ans == 0){
	//				printf("%d %d %d\n",i,j,k);
	//			}
	//		}
	//	}
	//}

	cin>>n;
	FOR(i,n) cin>>a[i];

	bool lgm = true;

	if(n == 1){
		lgm = a[0] != 0;
	} else if(n == 2){
		sort(a,a+2);
		if(find(vp2.begin(),vp2.end(),Pii(a[0],a[1])) != vp2.end()){
			lgm = false;
		} else {
			lgm = true;
		}
	} else {
		sort(a,a+3);
		int ans = dfs3(a[0],a[1],a[2]);
		lgm = ans == 1;
	}

	puts(lgm ? "BitLGM" : "BitAryo");

	return 0;
}