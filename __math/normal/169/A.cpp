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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;


int main(){
	int n,a,b;
	cin >> n>>a>>b;
	vector<int> t(n);
	for(int i = 0; i < sz(t);i++){
		cin >> t[i];
	}
	sort(t.begin(),t.end());
	int ans = max(t[b] - t[b-1],0);
	cout << ans << endl;
	return 0;
}