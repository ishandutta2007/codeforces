#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

ll inv(ll a, ll b){
	return a-1 ? b - b*inv(b%a, a)/a : 1;
}

int main(){
	ll t, n;
	scanf("%lld %lld", &t, &n);
	vi as(n);
	scanf("%lld",&as[n-1]);
	rep(i,1,n) scanf("%lld", &as[i-1]);
	vector<ll> pre(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + as[i];
	ll sum = pre[n];
	ll d = gcd(sum, t);
	sum /= d, t /= d;
	ll mus = t==1 ? 1 : inv(sum%t, t);
	map<ll, vi> gs;
	rep(i,0,n)
		gs[pre[i]%d].push_back(i);
	vi ans(n, -1);
	trav(v, gs){
		vi u;
		trav(x, v.second)
			u.push_back(pre[x]/d);
		trav(x, u) x = x%t * mus % t;
		vector<pii> pas;
		rep(i,0,sz(v.second)) pas.emplace_back(u[i], -v.second[i]);
		sort(all(pas));
		pas.push_back(pas[0]);
		pas.back().first += t;
		rep(i,0,sz(pas)-1)
			ans[-pas[i].second] = pas[i+1].first - pas[i].first;
	}
	trav(x, ans) assert(x != -1);
	trav(x, ans) printf("%lld ",x);
	puts("");
}