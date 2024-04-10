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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n,m;
vector<int> e[ten(5)];

bool is_bus(){
	int left = -1;
	int right = -1;
	FOR(i,n){
		if(sz(e[i]) == 1){
			if(left == -1){
				left = i;
			} else if(right == -1){
				right = i;
			} else {
				return false;
			}
		} else if(sz(e[i]) != 2){
			return false;
		}
	}

	return (left != -1) && (right != -1);
}

bool is_ring(){
	FOR(i,n){
		if(sz(e[i]) != 2){
			return false;
		}
	}
	return true;
}

bool is_star(){
	int a = -1;
	FOR(i,n){
		if(sz(e[i]) != 1){
			if(a != -1) return false;
			a = i;
		} 
	}
	return true;
}

int main(){
	cin>>n>>m;
	FOR(i,m){
		int a,b; cin>>a>>b;
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	if(is_bus()){
		puts("bus topology");
	} else if(is_ring()){
		puts("ring topology");
	} else if(is_star()){
		puts("star topology");
	} else {
		puts("unknown topology");
	}

	return 0;
}