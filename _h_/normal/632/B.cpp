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
const ld pi = acos(-1);
const int mx = 5e5+1;
int main(){
	int n;
	scanf("%d",&n);
	ll p[mx];
	char ab[mx];
	rep(i,0,n) scanf("%lld",p+i);
	scanf(" %s",ab);
	ll d = 0;
	rep(i,0,n) d += p[i]*(ab[i]=='A' ? 1 : -1);
	ll ans = d;
	rep(i,0,n){
		d -= 2*p[i]*(ab[i]=='A' ? 1 : -1);
		ans = max(ans, d);
	}
	d = -d;
	rrep(i,0,n){
		d -= 2*p[i]*(ab[i]=='A' ? 1 : -1);
		ans = max(ans, d);

	}
	ll tot = 0;
	rep(i,0,n) tot += p[i];
	printf("%lld\n",(tot+ans)/2);
}