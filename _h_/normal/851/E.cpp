#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mx = 5e4+1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vi ispr(mx,1);
	rep(p,2,mx) if(ispr[p])
		for(int k = p+p; k < mx; k += p)
			ispr[k] = 0;

	int n;
	cin >> n;
	map<int,int> m;
	rep(_,0,n){
		int a;
		cin >> a;
		rep(p,2,mx) if(a%p==0){
			int k = -1;
			while(a%p==0){
				++k;
				a /= p;
			}
			m[p] |= 1<<k;
		}
		if(a > 1)
			m[a] |= 1;
	}
	
	map<int,int> dp;
	dp[0] = 0;

	function<int(int)> calc = [&](int s){
		if(dp.count(s)) return dp[s];
		int seen = 0;
		for(int k = 0; (1<<k)<=s; ++k){
			int a = s&((1<<k)-1), b = s^a;
			seen |= 1<<calc(a | (b>>(k+1)));
		}
		int ans = 0;
		while(seen&(1<<ans)) ++ans;
		return dp[s] = ans;
	};

	int sum = 0;

	trav(s, m) sum ^= calc(s.second);
	if(sum) puts("Mojtaba");
	else puts("Arpa");
}