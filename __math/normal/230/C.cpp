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

string s[100];
int t[100][10000];

int main(){
	memset(t,0x3f,sizeof(t));
	int n,m; cin>>n>>m;
	FOR(i,n) cin>>s[i];
	FOR(i,n){
		if(find(s[i].begin(),s[i].end(),'1') == s[i].end()){
			puts("-1");
			return 0;
		}
		//to right
		int last = s[i].find_last_of('1') - m;
		FOR(j,m){
			if(s[i][j] == '1'){
				last = j;
			}
			t[i][j] = min(t[i][j],j - last);
		}
		//to left
		last = s[i].find_first_of('1') + m;
		for(int j = m-1; j >= 0; j--){
			if(s[i][j] == '1'){
				last = j;
			}
			t[i][j] = min(t[i][j],last - j);
		}
	}

	int ans = INF;

	FOR(j,m){
		int val = 0;
		FOR(i,n){
			val += t[i][j];
		}
		ans = min(ans,val);
	}

	cout << ans << endl;

	return 0;
}