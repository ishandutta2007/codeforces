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
int n,m;
vector<int> v;

void solve()
{
	for (int i = 0; i < n; i++){
		int c = i % m;
		cout << v[c+1] << endl;
	}
}

int main(){
	cin>>n>>m;
	v.resize(m+1);
	if(m&1){
		v[1] = (m+1)/2;
		for (int i = 1; i < (m+1)/2; i++){
			v[2*i]   = (m+1)/2 - i;
			v[2*i+1] = (m+1)/2 + i;
		}
	} else {
		for (int i = 0; i < m/2; i++){
			v[2*i+1]   = m/2 - i;
			v[2*i+2] = m/2 + i+1;
		}
	}


	solve();

	return 0;
}