#define _USE_MATH_DEFINES
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
const int MODULO = 1000000009;
const int INF = 100000000; //1e8

using namespace std;

#define sz(v) ((int)v.size())
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define ten(n) ((int)1e##n)

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;


//BEGIN!!!

int s[ten(5)];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>s[i];

	int max_bit = 0;
	for(int i = 31; i >= 0; i--){
		bool all_0 = true,all_1 = true;
		FOR(j,n){
			if(s[j] & (1<<i)) all_0 = false;
			else all_1 = false;
		}
		if(!all_0 && !all_1){
			max_bit = i;
			break;
		}
	}

	vector<int> v;
	FOR(i,n) if(s[i] & (1<<max_bit)){
		v.push_back(i);
	}

	int ans = 0;
	FOR(i,sz(v)){
		// left
		int left;
		if(i == 0) left = 0;
		else left = v[i-1] + 1;
		int tmp = 0;
		for(int j = v[i]-1; j >= left; j--){
			tmp = max(tmp,s[j]);
			ans = max(ans,tmp ^ s[v[i]]);
		}
		//right
		int right;
		if(i == sz(v) - 1) right = n;
		else right = v[i+1];
		tmp = 0;
		for(int j = v[i] + 1; j < right; j++){
			tmp = max(tmp,s[j]);
			ans = max(ans,tmp ^ s[v[i]]);
		}
	}

	cout << ans << endl;

	return 0;
}