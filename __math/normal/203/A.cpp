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
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int main()
{
	int x,t,a,b,da,db;
	cin>>x>>t>>a>>b>>da>>db;
	int ta[400],tb[400];
	for (int i = 0; i < t; i++){
		ta[i] = max(0,a - i * da);
		tb[i] = max(0,b - i * db);
	}
	ta[t] = tb[t] = 0;

	for (int i = 0; i <= t; i++){
		for (int j = 0; j <= t; j++){
			if(ta[i] + tb[j] == x){
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");
	return 0;
}