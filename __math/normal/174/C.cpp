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
static const double EPS = 1e-10;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;

//BEGIN!!! 

int n;
int a[100000];
vector<Pii> ans;

int solve(int low,int start)
{
	int end = start;
	while(end < n){
		if(a[end] < low) break;
		else if(a[end] > low) end = solve(low+1,end);
		else end++;
	}
	ans.push_back(Pii(start+1,end));
	return end;
}

int main()
{
	cin >> n;
	FOR(i,n) cin >>a[i];

	solve(0,0);

	printf("%d\n",sz(ans)-1);
	FOR(i,sz(ans)-1) printf("%d %d\n",ans[i].first,ans[i].second);

	return 0;
}