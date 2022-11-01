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


int main()
{
	int n;
	cin>>n;
	string s; cin>>s;

	map<char,int> mp;
	FOR(i,(int)s.size()) mp[s[i]]++;
	string ret;
	for(map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if((*it).second % n != 0){
			puts("-1");
			return 0;
		}
		ret += string((*it).second / n, (*it).first);
	}

	FOR(i,n) cout << ret;
	cout << endl;

	return 0;
}