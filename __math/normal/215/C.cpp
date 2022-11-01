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
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)

ll dp[501][501];

int main()
{
	int n,m,s; cin>>n>>m>>s;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i * j % 2 == 0) continue;
			if(i * j < s) continue; //
			int mul = i * j - s;
			int add = 0;
			if(mul == 0) add = (i/2+1)*(j/2+1)*2-1;
			else {
				for(int k = 2; k <= i; k += 2){
					if(mul % k != 0) continue;
					int l = mul / k;
					if(l % 2 != 0) continue;
					if(l <= j)
						add++;
				}
				add *= 2;
			}
			dp[i][j] = add;
		}
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans += (n - i + 1) * (m - j + 1) * dp[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}