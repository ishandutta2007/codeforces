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
	char g[mx], p[mx];
	ll pw[mx], gh[mx];
	pw[0] = 1;
	rep(i,1,mx) pw[i] = pw[i-1]*rnd%md;
	scanf("%s %s",g,p);
	int a = strlen(g), b = strlen(p);
	gh[0] = 0;
	rep(i,0,a) gh[i+1] = (gh[i] + pw[i]*g[i])%md;
	ll ph = 0;
	rrep(i,0,b) ph = (ph*rnd + p[i])%md;
	int ans = 0;
	for(int ix = 0; ix+b <= a; ++ix){
		if((gh[ix+b]-gh[ix]+md-ph*pw[ix])%md == 0){
			ix += b-1;
			++ans;
		}
	}
	cout << ans << endl;
}