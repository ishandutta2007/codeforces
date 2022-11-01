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
	string a;
	string s;
	cin >> a >> s;
	sort(s.begin(),s.end());
	vector<char> si(s.begin(),s.end());
	for(int i = 0; i < sz(a); i++){
		if(a[i] < si.back()){
			a[i] = si.back();
			si.pop_back();
		}
	}

	cout << a << endl;
	return 0;
}