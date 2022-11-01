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
typedef pair<double,int> P;

#ifdef _DEBUG

template<typename T>
inline void debug_out(const T& x)
{
	cout << x;
}

template<typename T,int N>
inline void debug_out(const T (&x)[N])
{
	FOR(i,N){
		debug_out(x[i]);
		cout << "\t";
	}
}

template<typename T,int N,int M>
inline void debug_out(const T (&x)[N][M])
{
	FOR(i,N){
		debug_out(x[i]);
		cout << endl;
	}
}

template<typename T>
inline void debug_out(const vector<T>& x)
{
	FOREACH(it,x){
		debug_out(*it);
		cout << "\t";
	}
}

template<typename T,int N>
inline void debug_out(const vector<T>(&x)[N])
{
	FOR(i,N){
		debug_out(x[i]);
		cout << endl;
	}
}
#else

void dummy_func(){}

#define debug_out(x) dummy_func()
#endif


int n,m,r;

int d[60][60][60];
int query[60][60][60];

void solve(){
	int s,t,k;
	cin>>s>>t>>k;
	t--,s--;
	if(k >= n) k = n - 1;
	cout << query[k][s][t] << endl;
}

int main(){
	cin>>n>>m>>r;
	FOR(i,m)FOR(j,n)FOR(k,n) cin>>d[i][j][k];
	FOR(i,m)FOR(j,n)FOR(k,n)FOR(l,n){
		min_swap(d[i][k][l],d[i][k][j] + d[i][j][l]);
	}

	//FOR(i,m)FOR(j,n){FOR(k,n) debug_out(d[i][j][k]),cout<<"\t"; cout<<endl;}

	memset(query,0x7F,sizeof(query));
	FOR(i,m)FOR(j,n)FOR(k,n){
		min_swap(query[0][j][k],d[i][j][k]);
	}
	//FOR(j,n){FOR(k,n) debug_out(query[0][j][k]),cout<<"\t"; cout<<endl;}
	for(int i = 1; i < n; i++) FOR(k,n) FOR(l,n) FOR(z,n){
		min_swap(query[i][k][l],query[i-1][k][z] + query[0][z][l]);
	}

	while(r--){
		solve();
	}

	return 0;
}