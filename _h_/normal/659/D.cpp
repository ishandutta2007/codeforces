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
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	cin.sync_with_stdio(0);
	int n;
	cin >> n;
	vi xs(n+1), ys(n+1);
	rep(i,0,n+1) cin >> xs[i] >> ys[i];
	xs.pb(xs[1]), ys.pb(ys[1]);
	int ans = 0;
	rep(i,1,n+1){
		ans += 0 >= xs[i]*ys[i-1]-xs[i-1]*ys[i] + xs[i+1]*ys[i] - xs[i]*ys[i+1] + xs[i-1]*ys[i+1] - xs[i+1]*ys[i-1];
	}
	cout << ans << endl;
}