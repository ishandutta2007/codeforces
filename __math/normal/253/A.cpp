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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

template<class T>
void my_swap(T &a,T& b){
	a^=b^=a^=b;
}

int main(){

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n,m; cin>>n>>m;

	char c1 = 'B',c2 = 'G';

	if(n <= m){
		my_swap(n,m);
		my_swap(c1,c2);
	}

	char buf[500] = {};

	FOR(i,m){
		buf[i*2] = c1;
		buf[i*2+1] = c2;
	}



	FOR(i,n-m){
		buf[m*2+i] = c1;
	}

	cout << buf << endl;

    return 0;
}