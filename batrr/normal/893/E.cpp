#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <cstdio>
#include <stdio.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define iop(a) cout<<"Bag is here!!!"<<a<<endl
using namespace std;
const int maxn=1111111; 
ll q,x,y,mod=1e9+7,fact[maxn],revfact[maxn],pow2[maxn];
bool p[maxn];
ll binpow(ll a,ll b){
	if(b==0)
		return 1;
	ll c=binpow(a,b/2);
	if(b%2==0)
		return c*c%mod;
	else                    	
		return c*c%mod*a%mod;	
}
ll cc(ll a,ll b){
	return fact[b]*1ll*revfact[a]%mod*revfact[b-a]%mod;
}
void solve(){     
	ll ans=pow2[y-1],cnt=0;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			cnt=0;
			while(x%i==0)
				x/=i,cnt++;
		//	cout<<ans<<" "<<cnt<<" "<<x<<endl;
			ans=ans*1ll*cc(cnt,cnt+y-1)%mod;
		}
	}
	if(x!=1)
		ans=ans*1ll*cc(1,y)%mod;
	cout<<ans<<endl;
}
int main(){  
	fact[0]=1;
	for(int i=1;i<maxn;i++)
		fact[i]=fact[i-1]*i%mod;	
	revfact[maxn-1]=binpow(fact[maxn-1],mod-2);
//	cout<<revfact[maxn-1]<<" "<<fact[maxn-1]<<" "<<revfact[maxn-1]*fact[maxn-1]%mod;
	for(int i=maxn-2;i>=0;i--)
		revfact[i]=revfact[i+1]*(i+1)%mod;
	for(int i=2;i<1000;i++)
		if(p[i]==false)
			for(int j=2*i;j<1000;j+=i)
				p[j]=true;
	pow2[0]=1;
	for(int i=1;i<maxn;i++)
		pow2[i]=pow2[i-1]*2%mod;
	cin>>q;
//	cout<<fact[q]<<" "<<revfact[q]<<" "<<fact[q]*revfact[q]%mod<<endl;           
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		solve();
	}
	return 0;
}