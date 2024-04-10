#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <string.h>
#include <cassert>

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

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;

//BEGIN!!! 

int n,m,c;
int a[100000],b[100001];

int main()
{
	cin>>n>>m>>c;
	FOR(i,n) cin >> a[i];
	FOR(i,m) cin >> b[i+1];
	for(int i = 0; i < m; i++){
		b[i+1] += b[i];
	}

	int x = 0,y = 0; 
	FOR(i,n){
		y = min(m - 1,i);
		x = max(0, i - (n - m));
		int add = b[y+1] - b[x];
		a[i] += add;
	}

	FOR(i,n) printf("%d ",a[i] % c);
	printf("\n");

	return 0;
}