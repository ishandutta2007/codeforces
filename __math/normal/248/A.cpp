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

using namespace std;
typedef long long ll;
const int MODULO = 1000000009;
const int INF = 100000000; //1e8

using namespace std;

#define sz(v) ((int)v.size())
#define FOR(i,n) for(int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int l[10000],r[10000];


int main()
{
	int n;cin>>n;
	FOR(i,n) cin>>l[i]>>r[i];

	int t1 = 0,t2 = 0;
	FOR(i,n){
		t1 += l[i];
		t2 += r[i];
	}

	int t = min(t1,n-t1) + min(t2,n-t2);

	cout << t << endl;

	return 0;
}