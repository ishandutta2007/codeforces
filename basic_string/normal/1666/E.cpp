#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
int n,L,a[N],mn,mx,b[N];
bool chkmn(int x){
	int i,now=0;
	for(i=1;i<=n;++i){
		now+=x;
		if(now<=a[i])now=a[i];
		if(now>a[i+1])return 0;
	}
	return 1;
}
bool chkmx(int x){
	int i,now=0;
	for(i=1;i<=n;++i){
		now+=x;
		if(now>=a[i+1])now=a[i+1];
		if(now<a[i])return 0;
	}
	if(now<L)return 0;
	return 1;
}
vector<int>vmn,vmx;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,l,r,m;
	cin>>L>>n,a[n+1]=L;
	for(i=1;i<=n;++i)cin>>a[i];
	l=1,r=L;
	while(l<=r){
		m=l+r>>1;
		if(chkmn(m))l=m+1;else r=m-1;
	}
	mn=r;
	l=1,r=L;
	while(l<=r){
		m=l+r>>1;
		if(chkmx(m))r=m-1;else l=m+1;
	}
	mx=l;
//	for(i=1;i<=n;++i)b[i]=a[i+1];
	a[n]=L;
	for(i=1;i<=n;++i){
		while(vmx.size()&&mx*1ll*i-a[i]<=mx*1ll*vmx.back()-a[vmx.back()])vmx.pop_back();
		vmx.push_back(i);
		/*while(vmn.size()&&b[i]-mn*1ll*i<=b[vmn.back()]-mn*1ll*vmn.bavk())vmn.pop_back();
		vmn.push_back(i);*/
	}
	int now=0,tmx=0,tmn=0;
	for(i=1;i<=n;++i){
		//now+mn+(j-i)*1ll*mx>=a[j]
		cout<<now<<' ';
		//now+x+(vmx[tmx]-i)*1ll*mx=a[vmx[tmx]]-now-
		if(now+mn+(vmx[tmx]-i)*1ll*mx>=a[vmx[tmx]])now+=mn;else
		 now+=min(mx+0ll,a[vmx[tmx]]-now-(vmx[tmx]-i)*1ll*mx);
		if(vmx[tmx]==i)++tmx;
		cout<<now<<'\n';
		//if(vmn[tmn]==i)++tmn;
	}
}
/*
a[i]=a[i],a[n]=L
b[i]=a[i+1]
sum(1,i)>=a[i]
sum(1,i)<=a[i+1]
sum(1,i)<=b[i]
sum(1,n)>=L
mx*i-a[i]
b[i]-mn*i
*/