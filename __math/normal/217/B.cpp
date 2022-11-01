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

int dp[1000000];

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

Pii get_count(int l,int r){
	if(l == 0)
		return Pii(0,0);
	int nr =  r/l;
	Pii ret = get_count(r % l,l);
	ret.first += nr;
	ret.second += nr - 1;
	return ret;

}

string solve(int n,int r){
	if(n == 1){
		if(r == 1) return "0\nT";
		else return "IMPOSSIBLE";
	} else if(n == 2){
		if(r == 2) return "0\nTB";
		else return "IMPOSSIBLE";
	}

	int ans = INF;
	int mn = INF;

	for(int i = 1; i < r; i++){
		if(gcd(i,r) != 1) continue;
		Pii c = get_count(i,r);
		c.second -= 2;
		if(c.first == n){
			if(ans > c.second){
				ans = c.second;
				mn = i;
			}
		}
	}

	if(mn == INF)
		return  "IMPOSSIBLE";

	string ret = "";

	int a = mn,b = r;
	int c = 0;
	while(a != 0){
		ret += string(b/a,(c&1) ? 'T' : 'B');
		b %= a;
		swap(a,b);
		c++;
	}
	if(ret[0] == ret[1])
		ret[0] = (ret[0] == 'T') ? 'B' : 'T';
	ret[ret.size() - 1] = (ret[ret.size() - 1] == 'T') ? 'B' : 'T';
	reverse(ret.begin(),ret.end());
	if(ret[0] == 'B'){
		FOR(i,ret.size())
			ret[i] = (ret[i] == 'T') ? 'B' : 'T';
	}

	ans = 0;
	FOR(i,ret.size() - 1){
		ans += (ret[i] == ret[i+1]);
	}
	char buf[256]; sprintf(buf,"%d\n",max(ans,0));

	string ret2(buf);
	return ret2 + ret;
}

int main()
{
	int n,r; cin>>n>>r;

	cout << solve(n,r) << endl;

	return 0;
}