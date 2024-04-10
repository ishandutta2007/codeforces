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

char s[100000 * 10 + 10];
char strs[150000][10];
int m;

int cnt = 0;
int s_i = 0;

int solve(int i){
	if(i == m) return i;
	else if( i > m) return -1;
	if(strs[i][0] == 'p'){
		i++;
		strcpy(s+s_i,"pair<");
		s_i += 5;
		i = solve(i);
		if(i == m || i == -1) return -1;
		strcpy(s+s_i,",");
		s_i++;
		i = solve(i);
		if(i == -1) return -1;
		strcpy(s+s_i,">");
		s_i++;
	} else {
		strcpy(s+s_i,"int");
		s_i += 3;
		cnt++;
		i++;
	}

	return i;
}

int main(){

	int n;
	scanf("%d",&n);

	while(scanf("%s",strs[m]) != -1){
		m++;
	}

	int ret = solve(0);
	if(cnt != n || ret != m)
		ret = -1;

	if(ret != -1)
		cout << s << endl;
	else 
		cout << "Error occurred" << endl;

	return 0;
}