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
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int v1[ten(6)],v2[ten(6)];

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int main(){
	int n,m; scanf("%d%d",&n,&m);

	FOR(i,n){
		int tb[1000];
		FOR(j,m) scanf("%d",tb+j);
		int cnt = 0;
		for(int j = 0; j < m; j++){
			for(int k = j+1; k < m; k++){
				int a = fastMin(tb[j],tb[k]);
				if(a > v1[cnt]){
					v2[cnt] = v1[cnt];
					v1[cnt] = a;
				} else if(a > v2[cnt]){
					v2[cnt] = a;
				}
				cnt++;
			}
		}
	}

	int ln = m*(m-1)/2;
	int ans = *max_element(v2,v2+ln);

	cout << ans << endl;

}