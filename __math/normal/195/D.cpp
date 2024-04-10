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


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

ll k[100000],b[100000];
Pll kb[100000];


bool EQ(const Pll& x,const Pll& y){
	return x.second  * y.first == y.second * x.first;
}

bool GT(const Pll& x,const Pll& y){
	if(EQ(x,y)) return false;
	bool ret = (x.second  * y.first > y.second * x.first);
	if(y.first * x.first < 0) ret = !ret;
	return ret;
}

int main(){
	int n;
	cin>>n;
	int cnt = 0;
	for(int i= 0 ;i < n; i++){
		cin>>k[i]>>b[i];
		if(k[i] == 0) continue;
		kb[cnt].first = k[i]; kb[cnt].second = b[i];
		cnt++;
	}

	sort(kb,kb+cnt,GT);
	int ans = 0;
	int i = 0;
	while (i < cnt)
	{
		int c = i+1;
		while(c < cnt && EQ(kb[i],kb[c])) c++;
		ans++;
		i = c;
	}

	cout << ans << endl;

	return 0;
}