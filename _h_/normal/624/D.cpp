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
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector<vi> M;
const ll inf = 1LL<<60;
const ll md = 1e9+7;

vi as;
ll n,a,b;
ll ans = inf;

void solve(ll d){
	vi cnt(n+1);
	rep(i,0,n){
		ll rem = as[i]%d;
		cnt[i+1] = cnt[i];
		if(rem == 0) continue;
		else if(rem == d-1 || rem == 1){
			++cnt[i+1];
		} else{
			cnt[i+1] += 1e3;
		};
	}
	ll rek = inf;
	rep(i,0,n+1){
		ll c = i*a-b*cnt[i];
		rek = min(rek, -c);
		ans = min(ans, cnt[n]*b + c + rek);
	}
}

void fsk(ll x){
	for(ll i = 2; i*i <= x; ++i){
		if(x % i == 0){
			solve(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) solve(x);
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	as.resize(n);
	for(ll &aa : as) scanf("%lld",&aa);
	fsk(as[0]),fsk(as[0]-1),fsk(as[0]+1),fsk(as[n-1]),fsk(as[n-1]-1),fsk(as[n-1]+1);
	printf("%lld\n",ans);
}