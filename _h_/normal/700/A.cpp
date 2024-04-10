#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,l,v1,v2,k;
	cin >> n >> l >> v1 >> v2 >> k;
	n = (n-1)/k + 1;
	ld lo = 0, hi = l;
	while(hi-lo > 1e-10){
		ld mi = (hi + lo)/2;

		ld t = mi/v2;
		ld d = (v2-v1)*t;
		ld t1 = d/(v2+v1);
		ld f = (t + t1)*v1;
		if(f*(n-1) + mi < l)
			lo = mi;
		else
			hi = mi;
	}
	cout.precision(15);
	cout << (l-lo)/v1 + lo/v2 << endl;
}