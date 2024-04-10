#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
	ll n,t;cin>>n>>t;
	ll A[n+5],cum[n+5]; cum[0]=0;
	ll sum=0;
	for(int i=1;i<=n;++i) cin>>A[i],cum[i]=A[i],sum+=A[i];
	for(int i=1;i<=n;++i) cum[i]+=cum[i-1];
	
	ll ans=0;
	while(t>0){
		bool flag=false;
		ll sum=0,c=0;
	    for(int i=1;i<=n;++i){
		if(A[i]+sum<=t) ++c,sum+=A[i],flag=true;
	    }
	if(!flag) break;
	ll need=t/sum;
	ans+=(need*c);
	t%=sum;
    }
    cout<<ans;
	return 0;
}