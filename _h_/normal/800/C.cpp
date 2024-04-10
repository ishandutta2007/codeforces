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

ll inv(ll a, ll b){
	return a-1 ? b-b*inv(b%a, a)/a : 1;
}

int div(int a, int b, int m){
	int d = __gcd(m,b);
	a /= d, b /= d, m /= d;
	return a*inv(b,m) % m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	vector<bool> forbidden(m);
	rep(_,0,n){
		int x;
		cin >> x;
		forbidden[x] = 1;
	}

	vi d;
	rep(i,1,m+1) if(m%i == 0) d.push_back(i);

	int s = sz(d);
	vector<vi> val(m+1);
	rep(i,0,m) if(!forbidden[i])
		val[__gcd(i, m)].push_back(i);
	vi dp(s), pek(s,-1);
	rrep(i,0,s){
		rep(j,i+1,s) if(d[j]%d[i] == 0){
			if(dp[i] < dp[j]){
				pek[i] = j;
				dp[i] = dp[j];
			}
		}
		dp[i] += sz(val[d[i]]);
	}
	cout << dp[0] << endl;
	int i = 0;
	int prev = 1;
	while(i != -1){
		trav(prod, val[d[i]]){
			assert(__gcd(prod,m) % __gcd(prev,m) == 0);
			cout << div(prod, prev, m) << ' ';
			prev = prod;
		}
		i = pek[i];
	}
	cout << endl;
}