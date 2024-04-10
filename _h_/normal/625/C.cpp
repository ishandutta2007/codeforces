#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
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
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;
const double pi = acos(-1);
const ll rnd = 54321;
const int mx = 1e5+5;

int main(){
	int n,k;
	cin >> n >> k;
	vector<vi> ans(n,vi(n));
	int ix = 1;
	rep(i,0,n) rep(j,0,k-1) ans[i][j] = ix++;
	ix = n*n;
	rep(i,0,n) rrep(j,k-1,n) ans[i][j] = ix--;
	int res = 0;
	rep(i,0,n) res += ans[i][k-1];
	cout << res << endl;
	rep(i,0,n){
		rep(j,0,n) cout << ans[i][j] << ' ';
		cout << endl;
	}
}