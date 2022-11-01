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

int petya(int n[2]){
	int ans = 0;
	int cnt = n[0] + n[1];
	int last = -1;
	for(int i = 0; i < cnt; i++){
		int selected;
		if(i % 2 == 0){
			if(i==0){
				selected = 0;
			} else {
				selected = (n[last] != 0) ? last : 1 - last;
			}
		} else {
			selected = (n[1 - last] != 0) ? 1 - last : last;
		}
		if(i != 0){
			if(last == selected) ans++;
		}
		last = selected;
		n[selected]--;
	}

	return ans;
}

int main()
{
	int n,m; cin>>n>>m;
	int a[2] = {n,m};
	int ans = petya(a);
	int b[2] = {m,n};
	ans = max(ans,petya(b));

	printf("%d %d\n",ans,n+m-1-ans);

	return 0;
}