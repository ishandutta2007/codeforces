#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define allof(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define max(a,b) ((a)<(b)?(b):(a))
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

ll sumnats(ll a){
	return (a*(a+1))/2;
}

ll exct(ll a, ll b, ll c, ll l){
	ll ans = ((l+2)*(l+1))/2;
	ll h = 1+(a+b+c+l-1)/2;
	ans -= h-a > l ? 0 : sumnats(l-max(0,(h-a))+1);
	ans -= h-b > l ? 0 : sumnats(l-max(0,(h-b))+1);
	ans -= h-c > l ? 0 : sumnats(l-max(0,(h-c))+1);
	return ans;
}

int main(){
	ll a,b,c,l;
	cin >> a >> b >> c >> l;
	ll ans = 0;
	rep(i,0,l+1)
		ans += exct(a,b,c,i);
	cout << ans << endl;
}