#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200009],ans=2e9;
map<ll,bool>mp;
mt19937 rd(time(0));
void work(ll x){
	if(mp[x])return;
	ll s=0,t;
	for(int i=0;i<n;++i)t=a[i]%x,s+=a[i]<x?(x-t):min(t,x-t);
	ans=min(ans,s),mp[x]=1;
}
void fac(ll x){
	for(ll i=2;i*i<=x;++i){
		if(!(x%i)){
			work(i);
			do x/=i;while(!(x%i));
		}
	}
	if(x>1)work(x);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%lld",a+i);
	for(i=0;i<30;++i)j=rd()%n,fac(a[j]-1),fac(a[j]),fac(a[j]+1);
	printf("%lld\n",ans);
	return 0;
}