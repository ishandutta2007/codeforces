#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
template<typename A, typename B>
A& operator*=(A &a, const B &b) {
  a = a * b;
  return a;
}
template<typename A, typename B>
A& operator-=(A &a, const B &b) {
	a = a - b;
	return a;
}
template<typename A, typename B>
A& operator+=(A &a, const B &b) {
	a = a + b;
	return a;
}
template<typename A, typename B>
A& operator/=(A &a, const B &b) {
	a = a / b;
	return a;
}
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		b/=2;
		a=a*a%MOD;
	}
	return ans;
}
struct mint {
	mint(ll x): x(x) {}
	mint() {}
	ll x;
};
ostream& operator<<(ostream &p, mint a) {
	p << a.x;
	return p;
}
istream& operator>>(istream &p, mint &a) {
	p >> a.x;
	return p;
}
mint operator+(mint a, mint b) {
	return (a.x+b.x)%MOD;
}
mint operator-(mint a, mint b) {
	return (a.x-b.x+MOD)%MOD;
}
mint operator*(mint a, mint b) {
	return (a.x*b.x)%MOD;
}
mint operator/(mint a, mint b) {
	return (a.x*pot(b.x, MOD-2))%MOD;
}
void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<pair<int,int>>ans;
	rep(i, n) {
		if(k>1 && i%2==1) {
			for(int j=i; j<n; ++j) if(s[j]==')') {
				ans.pb({i, j});
				reverse(s.begin()+i, s.begin()+j+1);
				--k;
				break;
			}
		} else {
			for(int j=i; j<n; ++j) if(s[j]=='(') {
				ans.pb({i, j});
				reverse(s.begin()+i, s.begin()+j+1);
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.st+1 << " " << i.nd+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}