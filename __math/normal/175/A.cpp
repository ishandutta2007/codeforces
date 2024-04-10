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

int g(vector<int>&a, int l,int r)
{
	if(l == r) return a[l];
	else if(a[l] == 0 || l - r > 6) return -1;

	int ans = 0;
	for(int k = l; k <= r; k++)
		ans = ans * 10 + a[k];
	if(ans > 1000000) return -1;
	return ans;
}

int main()
{
	string s;
	cin>>s;
	vector<int> a(s.begin(),s.end());
	FOREACH(it,a) *it -= '0';

	int ans = -1;
	for(int i = max(0,sz(a) - 15); i < min(sz(a) - 1,7); i++){
		for(int j = 0; j < 7 && i + j + 2 <= sz(a) - 1; j++){
			if(i + j < sz(a) - 9) continue;
			int l[3];
			l[0] = g(a,0,i);
			l[1] = g(a,i+1,i + j + 1);
			l[2] = g(a,i + j + 2,sz(a) - 1);
			if(l[0] == -1 || l[1] == -1 || l[2] == -1) continue;
			ans = max(ans,l[0]+l[1]+l[2]);
		}
	}

	cout << ans << endl;

	return 0;
}