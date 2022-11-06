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

void fail(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int pos = 0;
	rep(_,0,n){
		int t;
		string dir;
		cin >> t >> dir;
		if(pos > 0 || pos < -20000) fail();
		if(pos == 0 && dir != "South") fail();
		if(pos == -20000 && dir != "North") fail();
		if(dir == "South") pos -= t;
		else if(dir == "North") pos += t;
	}
	if(pos != 0) fail();
	cout << "YES" << endl;
}