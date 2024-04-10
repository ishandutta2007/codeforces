#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

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

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int a[100000];
bool b[4000001];

int main(){

	int n = 0; cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(i,n) b[a[i]] = true;
	vector<int> x,y;
	FOR(i,n){
		y.clear();
		int c = a[i];
		FOR(j,sz(x)){
			int d= x[j] | c;
			b[d] = true;
			y.push_back(d);
		}
		y.push_back(c);
		sort(y.begin(),y.end());
		y.erase(unique(y.begin(),y.end()),y.end());
		x.swap(y);
	}

	cout << accumulate(b,b+sizeof(b),0) << endl;

	return 0;
}