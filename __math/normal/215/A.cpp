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

int n,m;
int a[10000],b[10000];


int main()
{
	cin>>n;
	FOR(i,n) cin>>a[i];
	cin>>m;
	FOR(i,m) cin>>b[i];
	vector<int> anss;
	FOR(i,n) FOR(j,m){
		if( b[j] % a[i] == 0){
			anss.push_back(b[j] / a[i]);
		}
	}
	sort(anss.begin(),anss.end());
	int a = *(anss.end() - 1);
	int ans = upper_bound(anss.begin(),anss.end(),a) - lower_bound(anss.begin(),anss.end(),a);

	cout << ans << endl;

	return 0;
}