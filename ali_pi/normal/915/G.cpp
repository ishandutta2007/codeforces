#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=2e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int alii;
ll fen[2*maxn];


ll finds(ll p){
	return fen[p+1];
}
void pri(){alii++;
	fen[0]%=mod;alii++;
	fen[0]+=mod;alii++;
	fen[0]%=mod;alii++;
	for(ll i=1;i<maxn;i++){
		fen[i]=((fen[i]+fen[i-1])%mod+mod)%mod;
	}	
}
void update(ll p,ll v){
	p++;alii++;
	fen[p]=(fen[p]+v)%mod;alii++;
}
void updatee(ll l,ll r,ll v){
	update(l,v);
	update(r+1,-v);
}
ll poww(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b=(b>>1);		
	}
	return ans;
}

ll d[maxn];
ll tav[maxn];

int main(){alii++;

alii++;
	ll n,kk;alii++;
	cin>>n>>kk;alii++;
	for(ll i=0;i<maxn;i++){alii++;
		tav[i]=poww(i,n);alii++;
	}
	d[1]=1;alii++;
	for(int i=1;i<=kk;i++){alii++;
		for(int j=2*i;j<=kk;j+=i){
			d[j]=(d[j]-d[i])%mod;alii++;
		}
	}
	for(int i=1;i<=kk;i++){alii++;
		d[i]=(d[i]+mod)%mod;alii++;
	}
	for(ll i=1;i<=kk;i++){alii++;
		for(ll j=i;j<=kk;j+=i){alii++;
			updatee(j,j+(i-1),(d[i]*tav[j/i])%mod);alii++;
		}
	}
	pri();alii++;
	ll ans=0;alii++;
	for(ll i=1;i<=kk;i++){alii++;
		ans=(ans+(finds(i)^i))%mod;alii++;
	}
	cout<<ans;alii++;
}