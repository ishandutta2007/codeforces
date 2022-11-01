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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main(){
	int HP[2], ATK[2], DEF[2];
	FOR(i, 2) cin >> HP[i] >> ATK[i] >> DEF[i];
	int h, a, d; cin >> h >> a >> d;
	ll ans = ten(8) * ll(ten(8));
	FOR(j, 250) FOR(k, 250){

		int myatk = ATK[0] + j;
		int mydef = DEF[0] + k;
		int ehp = HP[1];
		int eatk = ATK[1];
		int edef = DEF[1];
		int my_dec = max(0, eatk - mydef);
		int e_dec = max(0, myatk - edef);
		if (e_dec == 0) continue;
		int time = (ehp + e_dec - 1) / e_dec;

		int mn_hp = time * my_dec + 1;
		ll i = max(mn_hp, HP[0]) - HP[0];

		ll money = i * h + j * a + k * d;
		ans = min(ans, money);
	}

	cout << ans << endl;
}