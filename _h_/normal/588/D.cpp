#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const ll md = 1e9+7;
int main(){
	int n,k,a;
	ll l;
	scanf("%d%lld%d",&n,&l,&k);
	map<int, int> kr;
	map<int, int> late;
	int gr = l%n == 0 ? n : l%n;
	rep(i,0,n){
		scanf("%d",&a);
		++kr[a];
		if(i >= gr)
			++late[a];
	}
	vi flat, lfl;
	for(auto par : kr){
		flat.push_back(par.second);
		lfl.push_back(late[par.first]);
	}
	int f = flat.size();
	vector<vl> dp(k, vl(f));
	rep(i,0,f)
		dp[0][i] = flat[i];
	ll bnum = (1+(l-1)/n);
	ll ans = l % md;
	rep(i,1,min((ll)k,bnum)){
		ll bef = 0;
		rep(j,0,f){
			bef = (bef+dp[i-1][j]) % md;
			dp[i][j] = bef*flat[j] % md;
			ans = (ans + (bnum%md - i)*dp[i][j] - bef*lfl[j]) % md;
		}
	}
	printf("%lld\n",(ans+md)%md);
}