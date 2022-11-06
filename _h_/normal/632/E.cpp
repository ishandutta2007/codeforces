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
#include <string>
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
const ld pi = acos(-1);
const int mil = 1e6;

int main(){
	int n,k;
	cin >> n >> k;
	vi as(n);
	for(int &a : as) cin >> a;
	sort(allof(as));
	int o = as[0];
	for(int &a : as) a -= o;
	vi c(mil, k+1);
	c[0] = 0;
	for(int &a : as){
		rep(i,a,mil)
			c[i] = min(c[i], 1+c[i-a]);
	}
	rep(i,0,mil) if(c[i] <= k) cout << i+k*o << ' ';
	cout << endl;
}