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
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vi x(n), y(n);
	rep(i,0,n) cin >> x[i] >> y[i];
	ll ans = 0;
	map<pii,int> cnt;
	rep(i,0,n) rep(j,i+1,n){
		pii p(x[i]+x[j], y[i]+y[j]);
		ans += cnt[p]++;
	}
	cout << ans << endl;
}