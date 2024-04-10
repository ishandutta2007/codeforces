#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef long long ll;

struct rat{
	ll p, q;
	rat(ll a, ll b) : p(a), q(b) {}
};

bool operator<(const rat &a, const rat &b){
	return a.p*b.q < b.p*a.q;
}

int main(){
	int n,c,d;
	scanf("%d%d%d",&n,&c,&d);
	multiset<rat> neg, pos;
	rep(i,0,n){
		int r,w;
		scanf("%d%d",&r,&w);
		r -= c, w -= d;
		if(w < 0 || (w == 0 && r < 0))
			neg.insert(rat(-r,-w));
		else
			pos.insert(rat(r,w));
	}
	ll ans = 0;
	int cnt = 0, negsz = neg.size(), possz = pos.size();
	auto it = neg.begin();
	for(auto r = pos.begin(); r != pos.end();){
		while(it != neg.end() && *it < *r){
			++cnt;
			++it;
		}
		int less = cnt;
		while(it != neg.end() && !(*r < *it)){
			++cnt;
			++it;
		}
		int samecnt = 0;
		rat old = *r;
		while(r != pos.end() && !(old < *r)){
			++samecnt;
			++r;
		}
		ans += (ll)samecnt*less*(negsz - cnt);
	}
	cnt = 0, it = pos.begin();
	for(auto r = neg.begin(); r != neg.end();){
		while(it != pos.end() && *it < *r){
			++cnt;
			++it;
		}
		int less = cnt;
		while(it != pos.end() && !(*r < *it)){
			++cnt;
			++it;
		}
		int samecnt = 0;
		rat old = *r;
		while(r != neg.end() && !(old < *r)){
			++samecnt;
			++r;
		}
		ans += (ll)samecnt*less*(possz - cnt);
	}
	printf("%lld\n",ans);
}