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

int m;
ll n;

int main(){
	cin >> n >> m;
	vector<ll> w(m);
	FOR(i, m){
		int p; cin >> p >> w[i];
	}
	while (sz(w) < ten(5)) w.push_back(0);

	sort(w.rbegin(), w.rend());
	ll ans = 0;
	vector<ll> v;
	for (ll i = 0; i < ten(4); i++){
		v.push_back(2 * i*i + i + 1);
		v.push_back(2 * (i + 1) * (i + 1));
	}

	for (int i = 0; n >= v[i]; i++){
		ans += w[i];
	}

	cout << ans << endl;

	return 0;
}