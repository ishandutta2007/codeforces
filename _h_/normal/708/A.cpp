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
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define trav(x,v) for(auto &x : (v))
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	int lo = 0;
	while(lo < sz(s) && s[lo]=='a')
		++lo;
	int hi = lo;
	while(hi < sz(s) && s[hi]!='a')
		++hi;
	if(lo==hi){
		lo = sz(s)-1, hi = sz(s);
	}
	rep(i,lo,hi){
		if(s[i] == 'a')
			s[i] = 'z';
		else
			s[i]--;
	}
	cout << s << endl;


}