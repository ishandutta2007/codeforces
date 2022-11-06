#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int lk[4][3] = {
	{0,0,0},
	{1,2,3},
	{2,3,1},
	{3,1,2},
};

ll f(ll n){
	ll r = n % 3, q = n / 3;

	int t = 0;
	while( (1LL<<(2*t)) <= q ){
		q -= 1LL<<(2*t);
		++t;
	}

	vi s(t+1,1);
	rrep(i,1,t+1){
		s[i] = q % 4;
		q /= 4;
	}

	ll ans = 0;
	trav(c, s) ans = ans * 4 + lk[c][r];
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;

	rep(_,0,t){
		ll n;
		cin >> n;
		cout << f(n-1) << endl;
	}
}