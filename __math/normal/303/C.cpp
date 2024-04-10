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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n,k,a[5000];

int mods[ten(6) + 1];
int non[ten(6) + 1];

//int diff_pair_count[ten(6) + 1];
//Pii diff_pair[ten(6) + 1][4];

int main(){
	cin>>n>>k;
	vector<int> a(n);
	FOR(i,n) cin>>a[i];
	sort(a.begin(),a.end());

	FOR(i,n) for(int j = i+1; j < n; j++){
		int diff = a[j] - a[i];
		mods[diff]++;
		if(mods[diff] > 10) mods[diff] = 10 + 1;
		//if(diff_pair_count [diff] < 4){
		//	diff_pair[diff][diff_pair_count[diff]++] = Pii(i,j);
		//}
	}

	for(int i = 1; i <= ten(6); i++){
		for(int j = i; j <= ten(6); j += i){
				non[i] += mods[j];
		}
	}

	int lim = k * (k+1) / 2;
	int ans = -1;
	static bool memo[ten(6) + 1];
	for(int i = 1; i <= ten(6) + 1; i++){
		if(non[i] <= lim){
			int rem = 0;
			memset(memo,0,i);
			FOR(j,n){
				int v = a[j] % i;
				if(memo[v]){
					rem++;
					if(rem > k) break;
				}
				memo[v] = true;
			}
			if(rem <= k){
				ans = i;
				break;
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}