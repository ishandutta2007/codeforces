#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1.5e6 + 123, mod = 998244353, inf = (int)1e9, LOG = 18;


map< ll , ll > cnt, cnt2;
int n;
ll ans, a[N];
vector< ll > v;


ll pw(ll x, ll k){
	ll res = 1;
	for(int i = 0; i < k; i++)
		res *= x;
	return res;
}
ll get(ll x, ll k){
	if(k == 4){
		for(ll i = 1; i * i * i * i <= x; i++)
			if(i * i * i * i == x)
				return i;
		return -1;
	}
	
	ll l = 0, r = 1e18;
	if(k == 2)
		r = 1.5e9;

	if(k == 3)
		r = 1.5e6;

	while(l <= r){
		ll m = (l + r) / 2;
		if(pw(m, k) < x)
			l = m + 1;
		else
			r = m - 1;
	}       
	while(pw(l, k) < x)
		l++;
	while(pw(l, k) > x)
		l--;
	if(pw(l, k) == x)
		return l;
	return -1;
}
void add(ll x){
	ll y;         
	y = get(x, 4);
	if(y != -1){
		cnt[y] += 4;
		return;	
	}
	y = get(x, 3);
	if(y != -1){
		cnt[y] += 3;
		return;	
	}
	y = get(x, 2);
	if(y != -1){
		cnt[y] += 2;
		return;	
	}
    cnt2[x]++;
}
int main(){
	ans = 1;
    scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		add(a[i]);
	}
	for(auto x : cnt2){
		bool ok = 0;
		for(int i = 0; i < n; i++){
			if(__gcd(a[i], x.f) != x.f && __gcd(a[i], x.f) != 1){
				cnt[__gcd(a[i], x.f)] += x.s;
				cnt[x.f/__gcd(a[i], x.f)] += x.s;
				ok = 1;
				break;
			}
		}
		if(!ok)
			ans = ans * (x.s + 1) * (x.s + 1) % mod ;
	}
	for(auto it : cnt)
		ans = ans * (it.s + 1) % mod;
	printf("%lld", ans);
}