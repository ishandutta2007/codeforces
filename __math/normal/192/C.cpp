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

int n;
char s[5*100000],t[5*100000];
int l[5*100000];

int dp[26][26];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char buf[16];
		cin>>buf;
		s[i] = buf[0] - 'a';
		l[i] = strlen(buf);
		t[i] = buf[l[i] - 1] - 'a';
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if(dp[j][s[i]] == 0) continue;
			max_swap(dp[j][t[i]], dp[j][s[i]] + l[i]);
		}
		max_swap(dp[s[i]][t[i]],l[i]);
	}

	int mx = 0;
	for (int i = 0; i < 26; i++)
	{
		max_swap(mx,dp[i][i]);
	}

	cout << mx << endl;
	return 0;
}