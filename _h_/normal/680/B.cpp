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
	int n,a;
	cin >> n >> a;
	vi t(n);
	rep(i,0,n) cin >> t[i];
	--a;
	int ans = t[a];
	int l = a-1, r = a+1;
	while(l >= 0 || r < n){
		if(l < 0)
			ans += t[r];
		else if(r >= n)
			ans += t[l];
		else 
			ans += 2*(t[l]&&t[r]);
		--l, ++r;
	}
	cout << ans << endl;
}