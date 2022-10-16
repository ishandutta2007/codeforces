#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e5+5;
const int mod=1e9+7;

ll ksm(ll a,ll b) {ll s=1,m=a; while(b) {if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
ll inv(ll x) {return ksm(x,mod-2);}

int n,buc[N],pd;
ll s=1,ans=1;

int main(){
	cin>>n;
	for(int i=1,p;i<=n;i++)cin>>p,buc[p]++;
	for(int i=1;i<N;i++)s=s*(!pd&&buc[i]&1?buc[i]+1>>1:buc[i]+1)%(mod-1),pd|=buc[i]&1;
	for(int i=1;i<N;i++)if(buc[i])ans=ans*ksm(i,s*(!pd?buc[i]/2:buc[i]))%mod;
	cout<<ans<<endl;
	return 0;
}