// CodeForces.cpp : R\[ AvP[VGg |Cg`B
//

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

#ifdef _WIN32
#define typeof(X) std::identity<decltype(X)>::type //C++0x
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n;i++){
		int x,y;
		cin >> x >> y;
		a[i] = x * 51 + 50 - y;
	}
	sort(a.begin(),a.end());
	int b = a[sz(a) - k];
	cout << upper_bound(a.begin(),a.end(),b) - lower_bound(a.begin(),a.end(),b) << endl;
	return 0;
}