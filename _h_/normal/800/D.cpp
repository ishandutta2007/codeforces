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

const int lg = 6;
const int m = 1000000;
const ll md = 1e9+7;

ll a[m], b[m], c[m], g[m], tva[m+10], cnt[m];
int tio[lg+1];

int main(){ 

	tva[0] = 1;
	rep(i,1,m+10) tva[i] = tva[i-1]*2 % md;
	tio[0] = 1;
	rep(i,0,lg) tio[i+1] = tio[i]*10;

	int n;
	scanf("%d",&n);
	rep(_,0,n){
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	ll ans = 0;

	rrep(i,1,m){
		int nines = 0;
		rep(s,0,lg){
			if(i%(int)tio[s+1] >= 9*tio[s]) nines += 1<<s;
		}
		ll myg = 0;
		rep(msk,1,1<<lg) if((msk & nines) == 0){
			int e = __builtin_popcount(msk)&1 ? 1 : -1;
			int j = i;
			rep(s,0,lg) if(msk&(1<<s)) j += tio[s];
			a[i] += e*a[j];
			b[i] += e*b[j];
			c[i] += e*c[j];
			myg -= e*g[j];
		}
		a[i] += (ll)cnt[i]*i;
		b[i] += (ll)cnt[i]*i%md*i;
		c[i] += cnt[i];
		a[i] %= md;
		b[i] %= md;

		ll s2 = a[i]*a[i]-b[i];
		s2 %= md;
		s2 *= (md+1)/2;
		s2 %= md;

		if(c[i]) g[i] = (b[i] + s2)%md*tva[c[i]-1]%md;

		myg += g[i];
		myg %= md;
		if(myg < 0) myg += md;
		
		ans ^= i*myg;
	}
	printf("%lld\n",ans);
}