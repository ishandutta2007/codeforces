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
#ifdef ONLINE_JUDGE
#define typeof(X) __typeof(X)
#else
#define typeof(X) decltype(X)
#endif
#define FOREACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define sz(c) ((int)(c).size())


int main(){
	int cur_max = 0,cur_min = 0;
	int mx = 0;
	string s; cin>>s;
	FOR(i,sz(s)){
		if(s[i] == '+'){
			if(cur_min == 0)
				cur_max++;
			else
				cur_min++,cur_max++;
		}else {
			if(cur_max == 0)
				cur_min--;
			else
				cur_max--,cur_min--;
		}
	}

	cout << cur_max - cur_min << endl;

    return 0;
}