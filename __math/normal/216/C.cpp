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
#include <ctime>

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

#define FOR(i,n) for(int i = 0 ;i < (n); i++)

int n,m,k;

vector<int> solve(){
	vector<int> v;
	if(k == 1){
		for(int i = 1; i <= n+m; i += n - 1) v.push_back(i);
		return v;
	}

	FOR(i,k) v.push_back(1);
	v.push_back(n);

	int x = n + 1;
	int last = n + m;
	while(true){
		if(last < x) break;
		FOR(i,k-1) v.push_back(x);
		x += n - 1;
		if(last < x) break;
		v.push_back(x);
		x++;
	}

	return v;
}

int main()
{
	cin>>n>>m>>k;

	vector<int> v = solve();

	cout << v.size() << endl;
	FOR(i,(int)v.size()) printf("%d%c",v[i],i == (int)v.size() - 1 ? '\n' : ' ');

	return 0;
}