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
const int mx = 1e5+1;

int m,d,n;

vi tio;

ll solve(string &a){
	ll res = 0;
	vi v(n), mm(n+1);
	rep(i,0,n) v[i] = a[i]-'0';
	rep(i,0,n) mm[i+1] = (mm[i] + v[i]*tio[i])%m;
	vl dp(m);
	
	int e=0;
	while(e<n && ((v[e]==d) == (e%2==1))) ++e;

	dp[0] = 1;
	res += e==n && mm[n] == 0;
	rrep(i,0,n){
		if(i%2 == 1){
			if(d < v[i] && i<=e){
				res += dp[(20*m-mm[i]-d*tio[i])%m];
			}
			vl nw(m);
			rep(j,0,m) nw[(j+d*tio[i])%m] += dp[j];
			dp = nw;
		} else {
			if(i<=e){
				rep(x,0,v[i]){
					if(x != d)
						res += dp[(20*m-mm[i]-x*tio[i])%m];
				}
			}
			vl nw(m);
			rep(x,0,10)
				if(x != d)
					rep(j,0,m) nw[(j+x*tio[i])%m] += dp[j];
			dp = nw;
		}
		//cout << res << endl;
		for(ll &x : dp) x %= md;
	}
	return res%md;
}

int main(){
	string a,b;
	cin >> m >> d >> a >> b;
	n = a.size();
	tio.resize(n);
	tio[n-1] = 1;
	rrep(i,0,n-1) tio[i] = tio[i+1]*10%m;
	rrep(i,0,n){
		if(a[i]=='0'){
			a[i] = '9';
		} else {
			a[i]--;
			break;
		}
	}
	//cout << solve(b) << endl;
	cout << (md+solve(b) - solve(a))%md << endl;
}