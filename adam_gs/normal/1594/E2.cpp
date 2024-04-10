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
const ll MOD=1e9+7;
ll pot(ll a, ll b, bool t) {
	ll ans=1;
	while(b) {
		if(b&1) {
			ans*=a;
			if(t) ans%=MOD;
		}
		a*=a;
		if(t) a%=MOD;
		b/=2;
	}
	return ans;
}
map<ll,ll>mp; // czy to poddrzewo zawiera specjalny wierzcholek
map<ll,ll>ile[4]; // jesli tak to licze dp
map<ll,ll>kol; // jaki kolor ma ten wierzcholek (jesli ma)
map<ll,ll>dodane;
ll dp[60];
ll poziom(ll k, ll x) {
	ll akt=1;
	while(akt<=x) {
		akt*=2;
		--k;
	}
	return k;
}
void solve() {
	ll k, n;
	cin >> k >> n;
	vector<ll>V;
	rep(i, n) {
		ll x;
		string s;
		cin >> x >> s;
		if(s[0]=='w' || s[0]=='y') {
			kol[x]=1;
		} else if(s[0]=='g' || s[0]=='b') {
			kol[x]=2;
		} else {
			kol[x]=3;
		}
		while(x && !dodane[x]) {
			dodane[x]=1;
			V.pb(x);
			x/=2;
		}
	}
	sort(all(V));
	reverse(all(V));
	dp[0]=1;
	for(int i=1; i<k; ++i) {
		dp[i]=(2*dp[i-1])%MOD;
		dp[i]=(dp[i]*dp[i])%MOD;
	}
	for(auto i : V) {
		ll p=poziom(k, i);
		if(p==0) {
			ile[kol[i]][i]=1;
			continue;
		}
		for(int a=1; a<=3; ++a) {
			for(int b=1; b<=3; ++b) {
				for(int c=1; c<=3; ++c) {
					if((kol[i]==a || kol[i]==0) && a!=b && a!=c) {
						ll ib=dp[p-1], ic=dp[p-1];
						if(dodane[2*i]) ib=ile[b][2*i];
						if(dodane[2*i+1]) ic=ile[c][2*i+1];
						ib=(ib*ic)%MOD;
						ile[a][i]=(ile[a][i]+ib)%MOD;
					}
				}
			}
		}
	}
	ll ans=ile[1][1]+ile[2][1]+ile[3][1];
	ans%=MOD;
	ll x=pot(2, k, false)-1-n;
	ll p=pot(2, x, true);
	ans=(ans*p)%MOD;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}