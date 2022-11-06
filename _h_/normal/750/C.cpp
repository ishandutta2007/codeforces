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
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int dif = 0;
	int mn = -1e8, mx = 1e8;
	rep(_,0,n){
		int c,d;
		cin >> c >> d;
		if(d == 1)
			mn = max(mn, 1900-dif);
		else
			mx = min(mx, 1899-dif);
		dif += c;
	}
	if(mn > mx) cout << "Impossible" << endl;
	else if(mx == 1e8) cout << "Infinity" << endl;
	else cout << mx+dif << endl;
}