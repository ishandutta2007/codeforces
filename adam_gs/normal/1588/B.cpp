#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
map<ll,ll>mp;
void solve() {
	int n;
	cin >> n;
	ll sum;
	cout << "? 1 " << n << endl;
	cin >> sum;
	ll p=0, k=n-1;
	while(p<k) {
		ll sr=(p+k)/2, a;
		cout << "? 1 " << sr+1 << endl;
		cin >> a;
		if(a<sum) p=sr+1; else k=sr;
	}
	cout << "? " << 1 << " " << p << endl;
	ll x;
	cin >> x;
	x=sum-x+1;
	ll y=sum-x*(x-1)/2;
	ll a=2, b=n;
	while(a<b) {
		ll sr=(a+b)/2;
		if(sr*(sr-1)/2<y) a=sr+1; else b=sr;
	}
	y=a;
	cout << "! " << p-x-y+2 << " " << p-x+2 << " " << p+1 << endl;
}
int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}