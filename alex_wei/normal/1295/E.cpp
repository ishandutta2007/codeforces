#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,x,sum,ans,pi[N],a[N],val[N<<2],laz[N<<2];
void pushdown(int p){
	if(laz[p]){
		val[p<<1]+=laz[p],val[(p<<1)|1]+=laz[p];
		laz[p<<1]+=laz[p],laz[(p<<1)|1]+=laz[p];
		laz[p]=0;
	}
	return;
}
void modify(int p,int l,int r,int ql,int qr,ll v){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		val[p]+=v,laz[p]+=v;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(p);
	modify(p<<1,l,mid,ql,qr,v);
	modify((p<<1)|1,mid+1,r,ql,qr,v);
	val[p]=min(val[p<<1],val[(p<<1)|1]);
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x,pi[x]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(i<n)modify(1,1,n-1,i,i,sum);
	}
	ans=val[1];
	for(int i=1;i<=n;i++){
		modify(1,1,n-1,1,pi[i]-1,a[pi[i]]),modify(1,1,n-1,pi[i],n-1,-a[pi[i]]);
		ans=min(ans,val[1]);
	}
	cout<<ans<<endl;
	return 0;
}