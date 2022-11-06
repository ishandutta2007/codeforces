#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;
typedef unsigned long long ull;

const ll md = 1e9+7;
const ll x0 = 1232381LL;

ull fun(ull x){
	rep(_,0,5){
		x *= 12329113923ULL;
		x ^= x >> 31;
	}
	return x % md;
}

int per(vector<ll> &v){
	int n = sz(v);
	vector<ll> pre(n+1);
	rep(i,0,n) pre[i+1] = (pre[i]*x0 + v[i]) % md;
	vector<ll> pow(n+1, 1);
	rep(i,0,n) pow[i+1] = pow[i] * x0 % md;
	rep(r,1,n+1) if(n % r == 0){
		if( (pre[n] - (pre[r]*(1-pow[n]) + pre[n]*pow[r]) ) % md == 0) return r;
	}
	return -1;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<ll> s1(n), s2(n/2);

	rep(_,0,m){
		int a, b;
		cin >> a >> b;
		a %= n, b %= n;
		if(a > b) swap(a,b);
		if((b-a)*2 == n){
			s2[min(a,b)]++;
		} else {
			if((b-a)*2 > n) swap(a,b);
			int l = (b-a+n)%n;
			s1[a] = (s1[a] + fun(l)) % md;
		}
	}
	trav(x, s1) x = fun(x);
	trav(x, s2) x = fun(x);

	ll a = per(s1);
	ll b = per(s2);
	ll res = a * b / __gcd(a,b);
	cout << (res<n ? "Yes" : "No") << endl;
}