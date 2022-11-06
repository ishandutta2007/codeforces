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
const ld eps = 1e-14;

ll choose(ll n, ll k){
	ll res = 1;
	rep(i,0,k) res = res*(n-i)/(i+1);
	return res;
}

int main(){
	ll x;
	cin >> x;
	x %= 360;
	if(x < 0) x += 360;
	if(x == 315) puts("0");
	else cout << (x+44)/90%4 << endl; 
}